N = int(input())
board = [[0] * 100 for _ in range(100)]

for _ in range(N):
    y1, x1 = map(int, input().split())
    for i in range(x1, x1 + 10):
        for j in range(y1, y1 + 10):
            board[i][j] = 1

result = sum(row.count(1) for row in board)
print(result)