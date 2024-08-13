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
중간에서 만나기 문제. 다양한 풀이가 있다.

1. Hash map
A+B와 C+D로 나누고 map에 넣는 현재 코드 풀이.
시간/공간복잡도 모두 O(N^2)인데 C++에선 unordered_map 기준 메모리 초과라고 한다.

2. Two pointers
A+B, C+D 모든 경우 벡터에 넣고 둘 다 정렬해 투 포인터.
경계조건 처리가 좀 성가실 수 있다. 시간 O(N^2 logN), 공간 O(N).
정렬을 2번 하지만 투 포인터 부분이 O(N)이라 언어 따라 BS보다 빠를 수 있다고 한다.

3. Binary search
합들 벡터에 넣고 하나만 정렬해서 lower_bound, upper_bound 사용.
정렬과 카운팅 모두 시간복잡도 O(N^2 logN). 복잡도는 투 포인터와 동일하다.
"""
