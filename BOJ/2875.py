import sys

input = sys.stdin.readline


if __name__ == "__main__":
    N, M, K = map(int, input().split())

    cnt = 0
    while N + M - K >= 3 and N >= 2 and M >= 1:
        N -= 2
        M -= 1
        cnt += 1
        
    print(cnt)