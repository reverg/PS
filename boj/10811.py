N, M = map(int, input().split())
basket = [i + 1 for i in range(N)]

for _ in range(M):
    i, j = map(int, input().split())
    basket[i - 1 : j] = reversed(basket[i - 1 : j])

for i in range(N):
    print(basket[i], end=" ")
