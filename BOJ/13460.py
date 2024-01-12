import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(input().strip()) for _ in range(N)]
visited = [[[[False] * M for _ in range(N)] for _ in range(M)] for _ in range(N)]
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]

for j in range(1, N - 1):
    for i in range(1, M - 1):
        if board[j][i] == "R":
            ry, rx = j, i
        elif board[j][i] == "B":
            by, bx = j, i

dq = deque()
dq.append((ry, rx, by, bx, 1))
visited[ry][rx][by][bx] = True


def move(y, x, dy, dx):
    cnt = 0
    while board[y + dy][x + dx] != "#" and board[y][x] != "O":
        y += dy
        x += dx
        cnt += 1
    return y, x, cnt


ans = -1
while dq:
    ry, rx, by, bx, cnt = dq.popleft()
    if cnt > 10:
        break
    for i in range(4):
        nry, nrx, rcnt = move(ry, rx, dy[i], dx[i])
        nby, nbx, bcnt = move(by, bx, dy[i], dx[i])

        if board[nby][nbx] != "O":
            if board[nry][nrx] == "O":
                ans = cnt
                dq.clear() # if not, bigger value can overwrite answer
                break

            if nry == nby and nrx == nbx:
                if rcnt > bcnt:
                    nry -= dy[i]
                    nrx -= dx[i]
                else:
                    nby -= dy[i]
                    nbx -= dx[i]

            if not visited[nry][nrx][nby][nbx]:
                visited[nry][nrx][nby][nbx] = True
                dq.append((nry, nrx, nby, nbx, cnt + 1))

print(ans)
