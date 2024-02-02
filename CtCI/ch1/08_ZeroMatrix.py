import sys

input = sys.stdin.readline


# Tiem: O(MN), Space: O(1)
def zero_matrix(matrix):
    rowHasZero = False
    colHasZero = False

    # check if there is a zero in first row
    for i in range(len(matrix[0])):
        if matrix[0][i] == 0:
            rowHasZero = True
            break

    # check if there is a zero in first column
    for j in range(len(matrix)):
        if matrix[j][0] == 0:
            colHasZero = True
            break

    # check zeros in left part
    for j in range(1, len(matrix)):
        for i in range(1, len(matrix[0])):
            if matrix[j][i] == 0:
                matrix[j][0] = 0
                matrix[0][i] = 0

    # replace rows to zero using first column
    for j in range(1, len(matrix)):
        if matrix[j][0] == 0:
            nullify_row(matrix, j)

    # replace columns to zero using first row
    for i in range(1, len(matrix[0])):
        if matrix[0][i] == 0:
            nullify_col(matrix, i)

    # replace first row to zero
    if rowHasZero:
        nullify_row(matrix, 0)

    # replace first column to zero
    if colHasZero:
        nullify_col(matrix, 0)

    return matrix


def nullify_row(matrix, row):
    for i in range(len(matrix[0])):
        matrix[row][i] = 0


def nullify_col(matrix, col):
    for i in range(len(matrix)):
        matrix[i][col] = 0


if __name__ == "__main__":
    matrix = []

    while True:
        line = input().rstrip()
        if line == "exit":
            break
        matrix.append(list(map(int, line.split())))

    zerofied = zero_matrix(matrix)
    for line in zerofied:
        print(line)
