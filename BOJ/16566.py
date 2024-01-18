import sys
from bisect import bisect_right

input = sys.stdin.readline


def find(v):
    if parent[v] != v:
        parent[v] = find(parent[v])
    return parent[v]


def union(v1, v2):
    p1, p2 = find(v1), find(v2)
    parent[p1] = p2


if __name__ == "__main__":
    N, M, K = map(int, input().split())
    card_list = list(map(int, input().split()))
    chulsoo = list(map(int, input().split()))
    card_list.sort()

    # Solution 1: Union-find for Minsu's card using binary search
    parent = [i for i in range(M + 1)]
    for target_card in chulsoo:
        idx = bisect_right(card_list, target_card)
        idx = find(idx)
        print(card_list[idx])
        union(idx, idx + 1)

    """
    # Solution 2: Union-find for all cards, no binary search
    # Slower than Solution 1
    parent = [i for i in range(N + 1)]
    parent[0 : card_list[0]] = [card_list[0]] * card_list[0]
    for idx in range(1, M):
        parent[card_list[idx - 1] + 1 : card_list[idx]] = [card_list[idx]] * (
            card_list[idx] - (card_list[idx - 1] + 1)
        )

    for target_card in chulsoo:
        submission = find(target_card + 1)
        print(submission)
        union(submission, find(min(submission + 1, N)))
    """
