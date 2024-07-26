import sys
from collections import deque

input = sys.stdin.readline


def bfs(init_status):
    if init_status == "123456780":
        return 0

    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    visited = set(init_status)
    dq = deque()
    dq.append((init_status, 0))

    while dq:
        (puzzle, cnt) = dq.popleft()

        cz = puzzle.index("0")  # position of zero
        cy, cx = cz // 3, cz % 3

        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if 0 <= ny < 3 and 0 <= nx < 3:
                # swap zero with another number
                nz = ny * 3 + nx
                puzzle_list = list(puzzle)
                puzzle_list[cz], puzzle_list[nz] = puzzle_list[nz], puzzle_list[cz]
                new_puzzle = "".join(puzzle_list)

                if new_puzzle == "123456780":
                    return cnt + 1

                if not new_puzzle in visited:
                    visited.add(new_puzzle)
                    dq.append((new_puzzle, cnt + 1))

    return -1


if __name__ == "__main__":
    puzzle = ""
    for i in range(3):
        puzzle += "".join(list(input().split()))

    print(bfs(puzzle))
