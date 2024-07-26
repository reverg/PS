import sys, copy

input = sys.stdin.readline


def collides(y, x, bishops):
    for bishop in bishops:
        ty, tx = bishop
        if abs(ty - y) == abs(tx - x):
            return True
    return False


def backtrack(loc, board, bishops):
    global max_cnt
    if loc == N**2:
        max_cnt = max(max_cnt, len(bishops))
        return

    y = loc // N
    x = loc % N

    if board[y][x] == 1 and not collides(y, x, bishops):
        board[y][x] = 2
        bishops.append((y, x))
        backtrack(loc + 1, board, bishops)
        board[y][x] = 1
        bishops.pop()

    backtrack(loc + 1, board, bishops)


if __name__ == "__main__":
    N = int(input())
    board = [list(map(int, input().split())) for _ in range(N)]
    white_board = copy.deepcopy(board)
    black_board = copy.deepcopy(board)
    for j in range(N):
        for i in range(N):
            if (j + i) % 2 == 0:
                white_board[j][i] = 0
            else:
                black_board[j][i] = 0

    # backtracking on white board
    bishops = []
    max_cnt = 0
    backtrack(0, white_board, bishops)
    white_tot = max_cnt

    # backtracking on black board
    bishops.clear()
    max_cnt = 0
    backtrack(0, black_board, bishops)
    black_tot = max_cnt

    print(white_tot + black_tot)
