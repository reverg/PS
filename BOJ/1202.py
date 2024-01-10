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
