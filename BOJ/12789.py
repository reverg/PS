import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
q = deque(map(int, input().split()))
st = []
get_snack = 1

while q:
    if q[0] == get_snack:
        q.popleft()
        get_snack += 1
    else:
        st.append(q.popleft())
    while st:
        if st[-1] == get_snack:
            st.pop()
            get_snack += 1
        else:
            break

print("Nice" if get_snack == N + 1 else "Sad")
