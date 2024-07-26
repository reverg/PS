import sys


input = sys.stdin.readline

if __name__ == "__main__":
    N, M = map(int, input().split())
    arr = list(map(int, input().split())) + [0]

    # two pointers
    i, j = 0, 0
    sum = 0
    cnt = 0

    while j <= N:
        if sum < M:
            sum += arr[j]
            j += 1
        else:
            sum -= arr[i]
            i += 1
        
        if sum == M:
            cnt += 1

    print(cnt)
