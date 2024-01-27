import sys

input = sys.stdin.readline

N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

C = []
i, j = 0, 0
len_a, len_b = len(A), len(B)
while i < len_a and j < len_b:
    if A[i] < B[j]:
        C.append(A[i])
        i += 1
    else:
        C.append(B[j])
        j += 1

while i < len_a:
    C.append(A[i])
    i += 1

while j < len_b:
    C.append(B[j])
    j += 1

print(*C)
