import math

S = input()
N = len(S)

r, c = 0, 0
for j in range(1, int(math.sqrt(N)) + 1):
    if N % j == 0:
        r, c = j, (N // j)

for j in range(r):
    for i in range(c):
        print(S[j + i * r], end="")
