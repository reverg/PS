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

    island_code = 1
    for j in range(N):
        for i in range(N):
            if board[j][i] == 1 and not visited[j][i]:
                group_island(j, i)
                island_code += 1

    min_dist = N * 2
    for i in range(island_code):
        min_dist = min(min_dist, build_bridge(i + 1))

    print(min_dist)

"""
섬마다 고유번호 부여 -> 1~K번 섬에서 가장 가까운 섬 BFS로 탐색.
지금 코드는 섬별로 따로 BFS를 돌렸지만 어느 섬에서 출발했는지 정보도
같이 넣으면 큐 하나에 다 넣고 돌릴 수 있다. 다리는 양방향으로 생길 수
있으므로 정보가 덮어써지는 문제는 일관성만 있으면 문제 없을 듯
(e.g. 번호가 작은 섬이 우선).  현재 코드에서는 기존 min_dist만큼 갔는데
다른 섬을 못 만나면 멈춰버리는 방법으로 조금 최적화가 가능하다.
O(N^2)를 N번 하므로 시간복잡도는 O(N^3)이다.
"""
