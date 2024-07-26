import sys

input = sys.stdin.readline


def magicFast(arr):
    return magicFastHelper(arr, 0, len(arr))


def magicFastHelper(arr, start, end):
    if end <= start:
        return -1

    mid = (start + end) // 2
    if arr[mid] == mid:
        return mid

    leftIdx = min(arr[mid] + 1, mid)
    left = magicFastHelper(arr, start, leftIdx)
    if left >= 0:
        return left

    rightIdx = max(arr[mid], mid + 1)
    right = magicFastHelper(arr, rightIdx, end)
    return right


if __name__ == "__main__":
    arr = list(map(int, input().split()))
    ans = magicFast(arr)
    print(ans)
