import sys

input = sys.stdin.readline

S = input().rstrip()

alphabets = dict()
for c in S:
    alphabets[c] = alphabets.get(c, 0) + 1

keys = sorted(alphabets.keys())
center = ""
for k in keys:
    if alphabets.get(k) % 2 == 1:
        center += k

if len(center) > 1:
    print("I'm Sorry Hansoo")
else:
    front_half = ""
    for k in keys:
        front_half += k * (alphabets.get(k) // 2)
    print(front_half + center + front_half[::-1])
