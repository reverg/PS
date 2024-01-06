import sys

input = sys.stdin.readline

N = int(input())

mem_list = set()
gomgomticon = 0
for _ in range(N):
    command = input().strip()
    if command == "ENTER":
        gomgomticon += len(mem_list)
        mem_list.clear()
    else:
        mem_list.add(command)

gomgomticon += len(mem_list)
print(gomgomticon)