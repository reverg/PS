import sys

input = sys.stdin.readline


if __name__ == "__main__":
    N = int(input())
    arr = [i for i in range(1, N + 1)]
    power_set = [[]]
    for i in range(N):
        power_set += [prev_set + [arr[i]] for prev_set in power_set]

    print(power_set)
