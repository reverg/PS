import sys

input = sys.stdin.readline

ipv6 = input().rstrip()
ipv6_parts = ipv6.split(":")
if ipv6_parts[0] == "":
    ipv6_parts = ipv6_parts[1:]
if ipv6_parts[-1] == "":
    ipv6_parts = ipv6_parts[:-1]

ipv4_parts = []
for p in ipv6_parts:
    if p == "":
        for _ in range(8 - len(ipv6_parts) + 1):
            ipv4_parts.append("0000")
    else:
        ipv4_parts.append(p.zfill(4))

ipv4 = ":".join(ipv4_parts)
print(ipv4)
