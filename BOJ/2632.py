import sys
from collections import defaultdict


input = sys.stdin.readline


def partSum(arr, size):
    part = defaultdict(int)
    for i in range(size):
        tmp = arr[i:] + arr[:i]
        pre = 0
        for num in tmp:
            pre += num
            part[pre] += 1
    part[sum(arr)] = 1
    return part


if __name__ == "__main__":
    S = int(input())
    M, N = map(int, input().split())
    A, B = [], []
    for _ in range(M):
        A.append(int(input()))
    for _ in range(N):
        B.append(int(input()))

    A_sum = partSum(A, M)
    B_sum = partSum(B, N)
    result = A_sum.get(S, 0) + B_sum.get(S, 0)
    for num in A_sum:
        if S - num in B_sum:
            result += A_sum[num] * B_sum[S - num]

    print(result)
