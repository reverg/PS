import sys

input = sys.stdin.readline

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]


def inboard(y, x):
    return 0 <= y < N and 0 <= x < M


def dfs(pos, loc):
    cy, cx = pos

    if dp[cy][cx][loc] != -1:
        return dp[cy][cx][loc]

    if loc == len(word):
        return 1

    cnt = 0
    for i in range(1, K + 1):
        for j in range(4):
            ny, nx = cy + i * dy[j], cx + i * dx[j]
            if inboard(ny, nx) and (board[ny][nx] == word[loc]):
                cnt += dfs((ny, nx), loc + 1)

    dp[cy][cx][loc] = cnt

    return dp[cy][cx][loc]


if __name__ == "__main__":
    N, M, K = map(int, input().split())
    board = [list(input().rstrip()) for _ in range(N)]
    word = list(input().rstrip())
    word.reverse()

    ans = 0
    # dp[y][x][l] = (y, x) 지점이 l번째 글자일 때 가능한 경우의 수
    dp = [[[-1] * (len(word) + 1) for _ in range(M)] for _ in range(N)]
    for j in range(N):
        for i in range(M):
            if board[j][i] == word[0]:
                ans += dfs((j, i), 1)

    print(ans)
