import sys, copy

input = sys.stdin.readline

N = 10


def press(y, x, board):
    board[y][x] = not board[y][x]
    if y > 0:
        board[y - 1][x] = not board[y - 1][x]
    if y < N - 1:
        board[y + 1][x] = not board[y + 1][x]
    if x > 0:
        board[y][x - 1] = not board[y][x - 1]
    if x < N - 1:
        board[y][x + 1] = not board[y][x + 1]


if __name__ == "__main__":
    bulbs = [
        [True if c == "O" else False for c in list(input().strip())] for _ in range(N)
    ]
    max_cnt = 101

    for k in range(1024):
        bulb_tmp = copy.deepcopy(bulbs)
        cnt = 0

        # check all cases for first line
        for col in range(10):
            if k & (1 << col):
                press(0, col, bulb_tmp)
                cnt += 1

        # press switch if upper line bulb is on
        for j in range(1, 10):
            for i in range(10):
                if bulb_tmp[j - 1][i]:
                    press(j, i, bulb_tmp)
                    cnt += 1

        # if all bulbs in the last line are off, check counter
        passed = True
        for i in range(10):
            if bulb_tmp[9][i]:
                passed = False
                break
        if passed:
            max_cnt = min(max_cnt, cnt)

    if max_cnt == 101:
        print(-1)
    else:
        print(max_cnt)
