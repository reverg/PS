def GCD(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        a, b = b, a % b
    return a


N = int(input())
min = max = int(input())
cur = int(input())
gcd = cur - min

for i in range(N - 2):
    next = int(input())
    gcd = GCD(gcd, next - cur)
    cur = next
max = cur

print(((max - min) // gcd) - N + 1)
