import sys
from collections import deque

input = sys.stdin.readline

answers = {}


def bfs():
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    dq = deque()
    dq.append(["12345678#", 0, 8])
    answers["12345678#"] = 0

    while dq:
        puzzle, cnt, cz = dq.popleft()
        cy, cx = divmod(cz, 3)

        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if 0 <= ny < 3 and 0 <= nx < 3:
                # swap zero with another number
                nz = ny * 3 + nx
                puzzle_list = list(puzzle)
                puzzle_list[cz], puzzle_list[nz] = puzzle_list[nz], puzzle_list[cz]
                new_puzzle = "".join(puzzle_list)

                if answers.get(new_puzzle) == None:
                    answers[new_puzzle] = cnt + 1
                    dq.append([new_puzzle, cnt + 1, nz])


if __name__ == "__main__":
    bfs()

    T = int(input())

    for _ in range(T):
        input()
        puzzle = ""
        for i in range(3):
            puzzle += "".join(list(input().split()))

        print(answers.get(puzzle, "impossible"))
