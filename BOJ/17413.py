import sys

input = sys.stdin.readline

st = []
res = ""
tag = False

S = input().rstrip()
for c in S:
    if c == "<":
        tag = True
        for _ in range(len(st)):
            res += st.pop()

    if c == " ":
        for _ in range(len(st)):
            res += st.pop()
        res += " "
    else:
        if tag:
            res += c
        else:
            st.append(c)

    if c == ">":
        tag = False

for _ in range(len(st)):
    res += st.pop()

print(res)
