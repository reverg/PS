import sys
from collections import deque

input = sys.stdin.readline


if __name__ == "__main__":
    F, S, G, U, D = map(int, input().split())

    dq = deque()
    dq.append([S, 0])
    visited = [False for _ in range(F + 1)]
    visited[S] = True
    ans = -1

    while dq:
        [curr_floor, cnt] = dq.popleft()
        if curr_floor == G:
            ans = cnt
            break

        for next_floor in (curr_floor + U, curr_floor - D):
            if 0 < next_floor <= F and not visited[next_floor]:
                visited[next_floor] = True
                dq.append([next_floor, cnt + 1])

    print(ans if ans != -1 else "use the stairs")
