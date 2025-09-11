import os, random
from collections import deque

DIRS = [(-1,0,'U'),(1,0,'D'),(0,-1,'L'),(0,1,'R')]

def find_start_and_free(grid):
    n,m=len(grid),len(grid[0])
    start=None
    free=[]
    for i in range(n):
        for j in range(m):
            if grid[i][j]=='O':
                start=(i,j)
                grid[i][j]='.'
            if grid[i][j]!='#':
                free.append((i,j))
    return start,free

def build_dfs_path(grid,start):
    n,m = len(grid), len(grid[0])
    visited = [[False]*m for _ in range(n)]
    path = [start]
    visited[start[0]][start[1]] = True
    stack = [start]

    while stack:
        x,y = stack[-1]
        # tìm láng giềng chưa thăm
        dirs = DIRS[:]
        random.shuffle(dirs)
        found = False
        for dx,dy,_ in dirs:
            nx,ny = x+dx, y+dy
            if 0<=nx<n and 0<=ny<m and grid[nx][ny] != '#' and not visited[nx][ny]:
                visited[nx][ny] = True
                stack.append((nx,ny))
                path.append((nx,ny))
                found = True
                break
        if not found:
            # backtrack
            stack.pop()
            if stack:
                path.append(stack[-1])
    return path

def compress_to_slide_commands(path):
    # Nén thành các lệnh trượt
    cmds=[]
    i=0
    while i+1<len(path):
        x,y=path[i]
        j=i+1
        dx=path[j][0]-x
        dy=path[j][1]-y
        if dx==0 and dy==0:
            i+=1
            continue
        # xác định hướng
        if dx<0: ch='U'
        elif dx>0: ch='D'
        elif dy<0: ch='L'
        else: ch='R'
        # trượt liên tục
        while j+1<len(path) and (path[j+1][0]-path[j][0],path[j+1][1]-path[j][1])==(dx,dy):
            j+=1
        cmds.append(ch)
        i=j
    return cmds

def solve_one(fin,fout):
    n,m,k=map(int,fin.readline().split())
    grid=[list(fin.readline().strip()) for _ in range(n)]
    start,free=find_start_and_free(grid)
    if start is None:
        fout.write('L'*k+'\n')
        return
    path=build_dfs_path(grid,start)
    cmds=compress_to_slide_commands(path)

    # Nếu thiếu lệnh, lặp lại vòng nhỏ quanh biên hoặc dao động
    if len(cmds)<k:
        filler=['L','R','U','D']
        idx=0
        while len(cmds)<k:
            cmds.append(filler[idx%4])
            idx+=1
    else:
        cmds=cmds[:k]
    fout.write(''.join(cmds)+'\n')

if __name__=='__main__':
    processed=0
    for i in range(10):
        if os.path.exists(f'input_{i}.txt'):
            with open(f'input_{i}.txt') as fin, open(f'output_{i}.txt','w') as fout:
                solve_one(fin,fout)
            processed+=1
    print(f"Đã xử lý {processed} file.")
