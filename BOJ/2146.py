import sys
from collections import deque

input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]


def inBoard(j, i):
    return 0 <= j < N and 0 <= i < N


def group_island(j, i):
    dq = deque()
    visited[j][i] = True
    board[j][i] = island_code
    dq.append((j, i))

    while dq:
        cy, cx = dq.popleft()
        for k in range(4):
            ny, nx = cy + dy[k], cx + dx[k]
            if inBoard(ny, nx) and board[ny][nx] != 0 and not visited[ny][nx]:
                visited[ny][nx] = True
                board[ny][nx] = island_code
                dq.append((ny, nx))


def build_bridge(code):
    dq = deque()
    visited = [[False for _ in range(N)] for _ in range(N)]

    for j in range(N):
        for i in range(N):
            if board[j][i] == code:
                visited[j][i] = True
                dq.append((j, i, 0))

    while dq:
        cy, cx, dist = dq.popleft()
        for k in range(4):
            ny, nx = cy + dy[k], cx + dx[k]
            if inBoard(ny, nx) and not visited[ny][nx]:
                if board[ny][nx] != 0:
                    return dist
                else:
                    visited[ny][nx] = True
                    dq.append((ny, nx, dist + 1))


if __name__ == "__main__":
    N = int(input())

    board = [list(map(int, input().split())) for _ in range(N)]
    visited = [[False for _ in range(N)] for _ in range(N)]

    island_code = 0
    for j in range(N):
        for i in range(N):
            if board[j][i] == 1 and not visited[j][i]:
                island_code += 1
                group_island(j, i)

    min_dist = N * 2
    for i in range(island_code):
        min_dist = min(min_dist, build_bridge(i + 1))

    print(min_dist)
