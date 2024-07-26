import sys

input = sys.stdin.readline


def merge_sort(A, p, r):
    if p < r:
        q = (p + r) // 2
        merge_sort(A, p, q)
        merge_sort(A, q + 1, r)
        merge(A, p, q, r)


def merge(A, p, q, r):
    global cnt, res
    i = p
    j = q + 1
    tmp = []

    while i <= q and j <= r:
        if A[i] <= A[j]:
            tmp.append(A[i])
            i += 1
        else:
            tmp.append(A[j])
            j += 1

    while i <= q:
        tmp.append(A[i])
        i += 1
    while j <= r:
        tmp.append(A[j])
        j += 1

    i = p
    t = 0
    while i <= r:
        A[i] = tmp[t]
        cnt += 1
        if cnt == K:
            res = A[i]
            break
        i += 1
        t += 1


N, K = map(int, input().rstrip().split())
A = list(map(int, input().rstrip().split()))
cnt = 0
res = -1
merge_sort(A, 0, N - 1)
print(res)
