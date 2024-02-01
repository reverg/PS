import sys

input = sys.stdin.readline


def count_bubbles(start, end):
    global arr

    # base condition
    if not start + 1 < end:
        return 0

    # divide and conquer
    mid = (start + end) // 2
    left_count = count_bubbles(start, mid)
    right_count = count_bubbles(mid, end)

    # merge left and right
    tmp = []
    bubble = 0
    i, j = start, mid
    while i < mid and j < end:
        if arr[i] <= arr[j]:
            tmp.append(arr[i])
            i += 1
        else:
            tmp.append(arr[j])
            j += 1
            bubble += mid - i
    if i < mid:
        tmp += arr[i:mid]
    if j < end:
        tmp += arr[j:end]

    # overwrite original array
    for i in range(len(tmp)):
        arr[start + i] = tmp[i]

    return left_count + right_count + bubble


if __name__ == "__main__":
    N = int(input())
    arr = list(map(int, input().split()))

    # in fact, this is merge sort
    print(count_bubbles(0, N))
