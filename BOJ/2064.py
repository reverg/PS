import sys

input = sys.stdin.readline


def printIP(ip):
    parts = []
    for _ in range(4):
        parts.append(str(ip & 255))
        ip = ip >> 8
    parts.reverse()
    return ".".join(parts)


N = int(input())

ip = []
for _ in range(N):
    s = input().rstrip().split(".")
    num = 0
    for p in s:
        num = num << 8
        num += int(p)
    ip.append(num)

subnet = 0
for i in range(31, -1, -1):
    ibit = 1 << i
    diff = False
    for j in range(1, N):
        if (ip[0] & ibit) != (ip[j] & ibit):
            diff = True
            break
    if diff:
        break
    else:
        subnet |= ibit

print(printIP(subnet & ip[0]))
print(printIP(subnet))
