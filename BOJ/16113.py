import sys

input = sys.stdin.readline

numbers = [
    ["#", "#", "#", "#", "#", "#", ".", ".", ".", "#", "#", "#", "#", "#", "#"],
    ["#", "#", "#", "#", "#"],
    ["#", ".", "#", "#", "#", "#", ".", "#", ".", "#", "#", "#", "#", ".", "#"],
    ["#", ".", "#", ".", "#", "#", ".", "#", ".", "#", "#", "#", "#", "#", "#"],
    ["#", "#", "#", ".", ".", ".", ".", "#", ".", ".", "#", "#", "#", "#", "#"],
    ["#", "#", "#", ".", "#", "#", ".", "#", ".", "#", "#", ".", "#", "#", "#"],
    ["#", "#", "#", "#", "#", "#", ".", "#", ".", "#", "#", ".", "#", "#", "#"],
    ["#", ".", ".", ".", ".", "#", ".", ".", ".", ".", "#", "#", "#", "#", "#"],
    ["#", "#", "#", "#", "#", "#", ".", "#", ".", "#", "#", "#", "#", "#", "#"],
    ["#", "#", "#", ".", "#", "#", ".", "#", ".", "#", "#", "#", "#", "#", "#"],
    [".", ".", ".", ".", "."],
]

N = int(input())
signal = list(input().rstrip())
line_len = len(signal) // 5

board = [
    signal[i * line_len : (i + 1) * line_len] for i in range(len(signal) // line_len)
]

temp = []
ans = []
for i in range(line_len):
    for j in range(5):
        temp.append(board[j][i])
        if temp == numbers[0]:
            ans.append(0)
            temp = []
        elif temp == numbers[1] and i < line_len - 1:
            if board[j][i + 1] == ".":
                ans.append(1)
                temp = []
        elif temp == numbers[1] and i == line_len - 1 and j == 4:
            ans.append(1)
            temp = []
        elif temp == numbers[2]:
            ans.append(2)
            temp = []
        elif temp == numbers[3]:
            ans.append(3)
            temp = []
        elif temp == numbers[4]:
            ans.append(4)
            temp = []
        elif temp == numbers[5]:
            ans.append(5)
            temp = []
        elif temp == numbers[6]:
            ans.append(6)
            temp = []
        elif temp == numbers[7]:
            ans.append(7)
            temp = []
        elif temp == numbers[8]:
            ans.append(8)
            temp = []
        elif temp == numbers[9]:
            ans.append(9)
            temp = []
        elif temp == numbers[10]:
            temp = []
for i in ans:
    print(int(i), end="")
