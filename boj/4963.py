import sys
from collections import deque

input = sys.stdin.readline

dy = [-1, 0, 1, 0, -1, -1, 1, 1]
dx = [0, -1, 0, 1, -1, 1, -1, 1]


def inBoard(j, i):
    return 0 <= j < h and 0 <= i < w


def bfs(j, i):
    dq = deque()
    visited[j][i] = True
    dq.append((j, i))

    while dq:
        cy, cx = dq.popleft()
        for k in range(8):
            ny, nx = cy + dy[k], cx + dx[k]
            if inBoard(ny, nx) and board[ny][nx] == 1 and not visited[ny][nx]:
                visited[ny][nx] = True
                dq.append((ny, nx))


if __name__ == "__main__":
    while True:
        w, h = map(int, input().split())
        if w == 0 and h == 0:
            break

        board = [list(map(int, input().split())) for _ in range(h)]
        visited = [[False for _ in range(w)] for _ in range(h)]

        island_cnt = 0
        for j in range(h):
            for i in range(w):
                if board[j][i] == 1 and not visited[j][i]:
                    bfs(j, i)
                    island_cnt += 1

        print(island_cnt)
