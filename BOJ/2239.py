import sys

input = sys.stdin.readline

board = [list(map(int, list(input().rstrip()))) for _ in range(9)]
row_check = [[False] * 10 for _ in range(9)]
column_check = [[False] * 10 for _ in range(9)]
box_check = [[False] * 10 for _ in range(9)]
for j in range(9):
    for i in range(9):
        if board[j][i]:
            row_check[j][board[j][i]] = True
            column_check[i][board[j][i]] = True
            box_check[3 * (j // 3) + (i // 3)][board[j][i]] = True


def check(y, x, val):
    row_exist = row_check[y][val]
    column_exist = column_check[x][val]
    box_exist = box_check[3 * (y // 3) + (x // 3)][val]
    return not (row_exist or column_exist or box_exist)


def backtrack(n):
    if n == 81:
        for i in board:
            print(''.join(map(str, i)))
        return True

    y = n // 9
    x = n % 9
    if board[y][x] != 0:
        return backtrack(n + 1)
    else:
        for i in range(1, 10):
            if check(y, x, i):
                row_check[y][i] = column_check[x][i] = box_check[
                    3 * (y // 3) + (x // 3)
                ][i] = True
                board[y][x] = i
                if backtrack(n + 1):
                    return True
                board[y][x] = 0
                row_check[y][i] = column_check[x][i] = box_check[
                    3 * (y // 3) + (x // 3)
                ][i] = False


backtrack(0)
