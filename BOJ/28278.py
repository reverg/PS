import sys
input = sys.stdin.readline

N = int(input())
st = []

for _ in range(N):
    command = input().split()
    if len(command) == 2:
        st.append(int(command[1]))
    elif command[0] == "2":
        if len(st) == 0:
            print(-1)
        else:
            print(st.pop())
    elif command[0] == "3":
        print(len(st))
    elif command[0] == "4":
        print(1 if len(st) == 0 else 0)
    elif command[0] == "5":
        if len(st) == 0:
            print(-1)
        else:
            print(st[-1])
