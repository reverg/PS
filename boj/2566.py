maxval = -1
x = 0
y = 0

table = [list(map(int, input().split())) for _ in range(9)]

for i in range(9):
    for j in range(9):
        if maxval < table[i][j]:
            maxval = table[i][j]
            x = i + 1
            y = j + 1

print(maxval)
print(x, y, sep=" ")
