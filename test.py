import random
import sys
from collections import deque

# Directions: (dx, dy, char)
DIRS = [(-1, 0, 'U'), (1, 0, 'D'), (0, -1, 'L'), (0, 1, 'R')]
OPP = {'U':'D','D':'U','L':'R','R':'L'}

def precompute_slides(grid):
    n, m = len(grid), len(grid[0])
    slide_path = [[[None]*4 for _ in range(m)] for __ in range(n)]
    slide_end = [[[(i,j) for _ in range(4)] for j in range(m)] for i in range(n)]
    for i in range(n):
        for j in range(m):
            if grid[i][j] == '#':
                continue
            for d, (dx, dy, ch) in enumerate(DIRS):
                path = []
                x, y = i + dx, j + dy
                while 0 <= x < n and 0 <= y < m and grid[x][y] != '#':
                    path.append((x, y))
                    x += dx
                    y += dy
                if path:
                    slide_path[i][j][d] = path  # list of cells passed in order
                    slide_end[i][j][d] = path[-1]
                else:
                    slide_path[i][j][d] = []   # no movement
                    slide_end[i][j][d] = (i, j)
    return slide_path, slide_end

def simulate_greedy_slide(grid, start, k, slide_path, slide_end, rng):
    n, m = len(grid), len(grid[0])
    x, y = start
    visited = set([start])
    res = []
    last_dir = None
    for step in range(k):
        best = None
        cand_list = []
        for d, (dx, dy, ch) in enumerate(DIRS):
            path = slide_path[x][y][d]
            if path is None:
                continue
            # count new cells that would be visited by this slide
            new_cells = 0
            for (cx, cy) in path:
                if (cx, cy) not in visited:
                    new_cells += 1
            length = len(path)
            # prefer new_cells, then longer slide, penalize repeating same move slightly
            repeat_penalty = -1 if last_dir == d else 0
            # random tie-breaker
            tie = rng.random()
            cand_list.append((new_cells, length, repeat_penalty, tie, d, ch, path))
        if not cand_list:
            # nowhere to move (all walls?) -> append arbitrary
            res.append('L')
            continue
        # pick best: sort by new_cells desc, length desc, repeat_penalty desc, random asc
        cand_list.sort(key=lambda t: (t[0], t[1], t[2], -t[3]), reverse=True)
        # If top has 0 new_cells, try to pick a direction that still moves (length>0) to relocate.
        top_new = cand_list[0][0]
        chosen = None
        if top_new > 0:
            chosen = cand_list[0]
        else:
            # look for any candidate with length>0 (actual slide)
            nonzero = [c for c in cand_list if c[1] > 0]
            if nonzero:
                # choose one among top few, prefer longer slides but randomize
                nonzero.sort(key=lambda t: (t[1], -t[3]), reverse=True)
                # randomize among top 2 to diversify
                idx = 0 if len(nonzero) == 1 else rng.choice([0, min(1, len(nonzero)-1)])
                chosen = nonzero[idx]
            else:
                # nothing moves — pick the highest-scoring (likely all zero-length)
                chosen = cand_list[0]

        _, _, _, _, didx, ch, path = chosen
        # append one command
        res.append(ch)
        # mark all intermediate cells visited and update position
        if path:
            for cell in path:
                visited.add(cell)
            x, y = slide_end[x][y][didx]
        else:
            # no movement, position unchanged
            pass
        last_dir = didx
    return ''.join(res), len(visited)

def solve_one_grid(grid, start, k, attempts=120, greedy_attempts=30):
    slide_path, slide_end = precompute_slides(grid)
    best_cmds = None
    best_score = -1
    # multiple attempts with randomness
    for a in range(attempts):
        rng = random.Random()  # local RNG
        rng.seed(random.randrange(1<<30) ^ (a * 10007))
        cmds, score = simulate_greedy_slide(grid, start, k, slide_path, slide_end, rng)
        if score > best_score:
            best_score = score
            best_cmds = cmds
            # optional early exit: if all reachable visited (hard to check cheaply), break
    # some additional short randomized greedy tries
    for a in range(greedy_attempts):
        rng = random.Random()
        rng.seed(random.randrange(1<<30) ^ (a * 7907))
        cmds, score = simulate_greedy_slide(grid, start, k, slide_path, slide_end, rng)
        if score > best_score:
            best_score = score
            best_cmds = cmds
    if best_cmds is None:
        # fallback
        best_cmds = 'L' * k
    return best_cmds

def solve(fin, fout):
    first = fin.readline().strip()
    while first == '':
        first = fin.readline().strip()
    n, m, k = map(int, first.split())
    grid = [list(fin.readline().rstrip('\n')) for _ in range(n)]
    start = None
    for i in range(n):
        for j in range(m):
            if grid[i][j] == 'O':
                start = (i, j)
                break
        if start:
            break
    # tune attempts relative to k to balance time/quality
    if k <= 50:
        attempts, greedy_attempts = 600, 200
    elif k <= 200:
        attempts, greedy_attempts = 300, 120
    elif k <= 800:
        attempts, greedy_attempts = 120, 40
    else:
        attempts, greedy_attempts = 80, 30

    res = solve_one_grid(grid, start, k, attempts=attempts, greedy_attempts=greedy_attempts)
    fout.write(res + '\n')

if __name__ == "__main__":
    random.seed()
    in_name = 'input_7.txt'
    out_name = 'output_7.txt'
    try:
        with open(in_name, 'r', encoding='utf-8') as fin, open(out_name, 'w', encoding='utf-8') as fout:
            solve(fin, fout)
        print(f"[OK] {in_name} -> {out_name}")
    except FileNotFoundError:
        print(f"[SKIP] {in_name} not found; skipping.")
    print("Done.")
