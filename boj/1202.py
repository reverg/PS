import sys
import heapq

input = sys.stdin.readline

N, K = map(int, input().split())
jewelleries = [list(map(int, input().split())) for _ in range(N)]
bags = [int(input()) for _ in range(K)]
jewelleries.sort()
bags.sort()

ans = 0
tmp_heap = []

for bag in bags:
    # get the jewelleries that can put in current bag
    while jewelleries:
        if bag >= jewelleries[0][0]:
            heapq.heappush(tmp_heap, -jewelleries[0][1])
            heapq.heappop(jewelleries)
        else:
            break

    # pick the most valuable jewellery
    if tmp_heap:
        ans += -heapq.heappop(tmp_heap)
    else:
        if not jewelleries:
            break

print(ans)

"""
그리디 문제. 가방의 크기가 증가하는 순서로 진행하면서
담을 수 있는 가장 가치가 높은 보석을 넣으면 된다.
증명은 귀류법을 사용하면 쉽게 가능하다. 보석의 가치가
높은 순서대로 해당 보석이 들어갈 수 있는 가장 작은 크기의
가방에 넣는 방법도 가능하다. 이 풀이에선 우선순위 큐를 썼는데,
다른 풀이는 multiset에 배낭을 넣고 lower_bound로 해당 가방을
찾아서 거기에 넣는 방식이 편하다.
"""
