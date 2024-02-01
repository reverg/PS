import sys
import heapq


input = sys.stdin.readline


def dijkstra():
    dy = [-1, 0, 1, 0]
    dx = [0, 1, 0, -1]

    hq = []
    heapq.heappush(hq, (0, 0, 0))
    dist[0][0] = 0

    while hq:
        cost, cy, cx = heapq.heappop(hq)
        if cy == N - 1 and cx == M - 1:
            return cost
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if 0 <= ny < N and 0 <= nx < M:
                if dist[ny][nx] == -1:
                    dist[ny][nx] = dist[cy][cx] + arr[ny][nx]
                    heapq.heappush(hq, (dist[ny][nx], ny, nx))


if __name__ == "__main__":
    M, N = map(int, input().split())
    arr = [list(map(int, input().rstrip())) for _ in range(N)]
    dist = [[-1] * M for _ in range(N)]

    print(dijkstra())
