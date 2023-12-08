N, K = map(int, input().split())
A = list(map(int, input().split(",")))
for _ in range(K):
    B = []
    for i in range(1, len(A)):
        B.append(A[i] - A[i - 1])
    A = B
print(*A, sep=",")
