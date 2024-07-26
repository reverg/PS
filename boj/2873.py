import sys

input = sys.stdin.readline


def rowOdd():
    path = (("R" * (C - 1) + "D") + ("L" * (C - 1) + "D")) * (R // 2)
    path += "R" * (C - 1)
    return path


def colOdd():
    path = (("D" * (R - 1) + "R") + ("U" * (R - 1) + "R")) * (C // 2)
    path += "D" * (R - 1)
    return path


def getSkipPoint():
    y, x = 0, 0
    min_happy = 1000
    for j in range(R):
        for i in range(C):
            if (j + i) % 2 == 1 and board[j][i] < min_happy:
                min_happy = board[j][i]
                y, x = j, i
    return (y, x)


def bothEven():
    skip_y, skip_x = getSkipPoint()
    path = ""

    # section 1: before skip point
    for _ in range(skip_x // 2):
        path += "D" * (R - 1) + "R" + "U" * (R - 1) + "R"

    # section 2: include skip point
    for _ in range(skip_y // 2):
        path += "RDLD"
    if skip_x % 2 == 0:
        path += "RD"
    else:
        path += "DR"
    for _ in range((R - skip_y - 1) // 2):
        path += "DLDR"

    # section 3: after skip point
    for _ in range((C - skip_x - 1) // 2):
        path += "R" + "U" * (R - 1) + "R" + "D" * (R - 1)

    return path


if __name__ == "__main__":
    R, C = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(R)]

    if R % 2 == 1:
        happiness_path = rowOdd()
    elif C % 2 == 1:
        happiness_path = colOdd()
    else:
        happiness_path = bothEven()

    print(happiness_path)
