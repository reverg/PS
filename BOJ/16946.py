import sys

input = sys.stdin.readline


def dfs(y, x):
    st = [(y, x)]
    cnt_size = 1

    while st:
        cy, cx = st.pop()
        group_id[cy][cx] = cnt_id
        for i in range(4):
            ny, nx = cy + dy[i], cx + dx[i]
            if (0 <= ny < N and 0 <= nx < M) and (
                not visited[ny][nx] and not board[ny][nx] == 1
            ):
                visited[ny][nx] = True
                st.append((ny, nx))
                cnt_size += 1

    return cnt_size


if __name__ == "__main__":
    N, M = map(int, input().split())
    board = [list(map(int, input().strip())) for _ in range(N)]
    visited = [[False] * M for _ in range(N)]
    group_id = [[-1] * M for _ in range(N)]
    cnt_id = 0
    group_size = []

    dy = [-1, 0, 1, 0]
    dx = [0, -1, 0, 1]

    # get group for each spaces
    for j in range(N):
        for i in range(M):
            if not visited[j][i] and board[j][i] == 0:
                visited[j][i] = True
                size = dfs(j, i)
                group_size.append(size)
                cnt_id += 1

    # break walls
    movable_space = [[0] * M for _ in range(N)]
    for j in range(N):
        for i in range(M):
            if board[j][i] == 1:
                movable_space[j][i] = 1
                added_group_list = [-1]
                for k in range(4):
                    ny, nx = j + dy[k], i + dx[k]
                    if (0 <= ny < N and 0 <= nx < M) and (
                        not group_id[ny][nx] in added_group_list
                    ):
                        movable_space[j][i] += group_size[group_id[ny][nx]]
                        added_group_list.append(group_id[ny][nx])
                movable_space[j][i] %= 10

    # print result
    for line in movable_space:
        print("".join(map(str, line)))
