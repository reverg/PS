import sys


input = sys.stdin.readline


if __name__ == "__main__":
    N = int(input())
    A, B, C, D = [], [], [], []
    for _ in range(N):
        a, b, c, d = map(int, input().split())
        A.append(a)
        B.append(b)
        C.append(c)
        D.append(d)

    sum_cnt = dict()
    for a in A:
        for b in B:
            u = a + b
            if u not in sum_cnt:
                sum_cnt[u] = 1
            else:
                sum_cnt[u] += 1

    ans = 0
    for c in C:
        for d in D:
            v = c + d
            if -v in sum_cnt:
                ans += sum_cnt[-v]

    print(ans)

"""
meet in the middle + hash map.
A+B와 C+D로 나누고 map에 넣어도 되고,
투 포인터로 같은 것 세줘도 된다.
"""