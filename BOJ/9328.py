import sys
from collections import deque

input = sys.stdin.readline

T = int(input())

dy = [0, 1, 0, -1]
dx = [-1, 0, 1, 0]


for _ in range(T):
    h, w = map(int, input().split())
    board = [["."] + list(input().strip()) + ["."] for _ in range(h)]
    board = [["."] * (w + 2)] + board + [["."] * (w + 2)]
    keys = set(input().upper().strip())
    locked_doors = dict()

    ans = 0

    dq = deque([[0, 0]])
    visited = [[False] * (w + 2) for _ in range(h + 2)]
    visited[0][0] = True

    while dq:
        cy, cx = dq.popleft()

        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]

            if not (0 <= ny < h + 2 and 0 <= nx < w + 2):
                continue
            if board[ny][nx] == "*" or visited[ny][nx]:
                continue

            if "A" <= board[ny][nx] <= "Z":  # door
                if not board[ny][nx] in keys:
                    if board[ny][nx] in locked_doors:
                        locked_doors[board[ny][nx]].append((ny, nx))
                    else:
                        locked_doors[board[ny][nx]] = [(ny, nx)]
                else:
                    board[ny][nx] = "."
                    visited[ny][nx] = True
                    dq.append((ny, nx))

            elif "a" <= board[ny][nx] <= "z":  # key
                key = board[ny][nx].upper()
                keys.add(key)
                if key in locked_doors:
                    for door in locked_doors[key]:
                        open_y, open_x = door
                        board[open_y][open_x] = "."
                        dq.append((open_y, open_x))
                    locked_doors.pop(key)
                board[ny][nx] = "."
                visited[ny][nx] = True
                dq.append((ny, nx))

            elif board[ny][nx] == "$":  # document
                board[ny][nx] = "."
                ans += 1
                visited[ny][nx] = True
                dq.append((ny, nx))

            else:  # empty space
                visited[ny][nx] = True
                dq.append((ny, nx))

    print(ans)
