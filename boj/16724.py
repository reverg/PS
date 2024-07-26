import sys

input = sys.stdin.readline

N, M = map(int, input().split())
board = [list(input()) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
group = [[-1 for _ in range(M)] for _ in range(N)]

def dfs(cy, cx, cyc_idx):
    global ans
    if group[cy][cx] != -1:
        if group[cy][cx] == cyc_idx:
            ans += 1
        return
    
    group[cy][cx] = cyc_idx

    ny, nx = cy, cx
    match board[cy][cx]:
        case "U":
            ny = cy - 1
            nx = cx
        case "D":
            ny = cy + 1
            nx = cx
        case "L":
            ny = cy
            nx = cx - 1
        case "R":
            ny = cy
            nx = cx + 1
            
    dfs(ny, nx, cyc_idx)

ans = 0
cyc_idx = 0
for j in range(N):
    for i in range(M):
        dfs(j, i, cyc_idx)
        cyc_idx += 1

print(ans)