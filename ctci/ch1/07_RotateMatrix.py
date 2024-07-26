import sys

input = sys.stdin.readline


# O(N^2)
def rotate_matrix(matrix):
    n = len(matrix)
    for layer in range(n // 2):
        first, last = layer, (n - 1) - layer
        for i in range(first, last):
            # save top
            top = matrix[layer][i]

            # left -> top
            matrix[layer][i] = matrix[-i - 1][layer]

            # bottom -> left
            matrix[-i - 1][layer] = matrix[-layer - 1][-i - 1]

            # right -> bottom
            matrix[-layer - 1][-i - 1] = matrix[i][-layer - 1]

            # top -> right
            matrix[i][-layer - 1] = top

    return matrix


if __name__ == "__main__":
    matrix = []

    while True:
        line = input().rstrip()
        if line == "exit":
            break
        matrix.append(list(line.split()))

    rotated = rotate_matrix(matrix)
    for line in rotated:
        print(line)
