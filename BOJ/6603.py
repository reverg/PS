import sys


input = sys.stdin.readline


def backtrack(cnt, pos):
    global seq
    if cnt == 6:
        print(*seq)

    for i in range(pos, k):
        seq.append(nums[i])
        backtrack(cnt + 1, i + 1)
        seq.pop()


if __name__ == "__main__":
    while True:
        line = list(map(int, input().split()))
        if len(line) == 1:
            break

        k = line[0]
        nums = line[1:]
        seq = []
        backtrack(0, 0)
        print()
