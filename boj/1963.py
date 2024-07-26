import sys
from collections import deque

input = sys.stdin.readline


if __name__ == "__main__":
    # get primes
    prime = [True for _ in range(10001)]
    prime[0] = prime[1] = False
    for i in range(2, 101):
        for j in range(10001):
            if j % i == 0:
                prime[j] = False

    # get prime path
    T = int(input())
    for _ in range(T):
        src, dst = map(int, input().split())
        visited = [False for _ in range(10001)]
        dq = deque()

        visited[src] = True
        dq.append((src, 0))

        ans = -1
        while dq:
            curr, dist = dq.popleft()
            if curr == dst:
                ans = dist
                break

            for i in range(4):
                for j in range(10):
                    if i == 0 and j == 0:
                        continue
                    str_next = list(str(curr))
                    str_next[i] = str(j)
                    next = int("".join(str_next))
                    if prime[next] and not visited[next]:
                        visited[next] = True
                        dq.append((next, dist + 1))

        print(ans if ans != -1 else "Impossible")
