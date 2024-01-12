import sys
from copy import deepcopy

input = sys.stdin.readline

N = int(input())
board = [list(map(int, input().strip().split())) for _ in range(N)]
ans = 0


def move(board, direction):
    match direction:
        case 0:  # up
            for i in range(N):
                top = 0
                for j in range(1, N):
                    if board[j][i]:
                        tmp = board[j][i]
                        board[j][i] = 0
                        if board[top][i] == 0:
                            board[top][i] = tmp
                        elif board[top][i] == tmp:
                            board[top][i] *= 2
                            top += 1
                        else:
                            top += 1
                            board[top][i] = tmp
        case 1:  # down
            for i in range(N):
                top = N - 1
                for j in range(N - 2, -1, -1):
                    if board[j][i]:
                        tmp = board[j][i]
                        board[j][i] = 0
                        if board[top][i] == 0:
                            board[top][i] = tmp
                        elif board[top][i] == tmp:
                            board[top][i] *= 2
                            top -= 1
                        else:
                            top -= 1
                            board[top][i] = tmp
        case 2:  # left
            for j in range(N):
                top = 0
                for i in range(1, N):
                    if board[j][i]:
                        tmp = board[j][i]
                        board[j][i] = 0
                        if board[j][top] == 0:
                            board[j][top] = tmp
                        elif board[j][top] == tmp:
                            board[j][top] *= 2
                            top += 1
                        else:
                            top += 1
                            board[j][top] = tmp
        case 3:  # right
            for j in range(N):
                top = N - 1
                for i in range(N - 2, -1, -1):
                    if board[j][i]:
                        tmp = board[j][i]
                        board[j][i] = 0
                        if board[j][top] == 0:
                            board[j][top] = tmp
                        elif board[j][top] == tmp:
                            board[j][top] *= 2
                            top -= 1
                        else:
                            top -= 1
                            board[j][top] = tmp
    return board


def backtrack(board, cnt):
    if cnt == 5:
        global ans
        max_elem = max(max(x) for x in board)
        ans = max(max_elem, ans)
        return

    for i in range(4):
        tmp_board = move(deepcopy(board), i)
        backtrack(tmp_board, cnt + 1)


backtrack(board, 0)
print(ans)
