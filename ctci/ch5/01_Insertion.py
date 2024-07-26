import sys

input = sys.stdin.readline

if __name__ == "__main__":
    M, N, i, j = input().rstrip().split()
    M = int(M, base=2)
    N = int(N, base=2)
    i = int(i)
    j = int(j)

    mask = ((~0) << (j + 1)) | ((1 << i) - 1)
    m_cleared = M & mask
    n_shifted = N << i

    print(bin(m_cleared | n_shifted))
