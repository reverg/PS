import sys

HEIGHT, CNT = 0, 1

input = sys.stdin.readline

N = int(input())
line = []
for _ in range(N):
    line.append(int(input()))
stack = []

ans = 0

for h in line:
    # If person in stack is smaller than current person:
    # all people who can see each other with him can see each other with current person
    while stack and stack[-1][HEIGHT] < h:
        ans += stack.pop()[CNT]

    # Append current person if stack is empty
    if not stack:
        stack.append((h, 1))
    else:
        # If stack top and current person have same height:
        # compress them to one
        if stack[-1][HEIGHT] == h:
            cnt = stack.pop()[CNT]
            ans += cnt
            
            # If there is a person in stack, the new man and he can see each other
            if stack:
                ans += 1
            
            # Put compressed man to stack
            stack.append((h, cnt + 1))

        else:
            # new man is smaller than stack top
            # he can only see stack top
            stack.append((h, 1))
            ans += 1

print(ans)
