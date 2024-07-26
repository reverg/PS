import re

N = int(input())
p = re.compile(".*".join(input().split("*")))

for _ in range(N):
    s = input()
    if p.fullmatch(s):
        print("DA")
    else:
        print("NE")
