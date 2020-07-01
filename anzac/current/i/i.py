r, c = map(int, input().split())

def pidx(x, y, r, c):
    return c*y + x

def height(grid, r, c, x, y):
    if 0 <= x <= c-1 and 0 <= y <= r-1:
        return grid[pidx(x, y, r, c)]
    else:
        return -1

def drain(grid, r, c, x, y):
    lt = height(grid, r, c, x-1, y)
    rt = height(grid, r, c, x+1, y)
    up = height(grid, r, c, x, y+1)
    dn = height(grid, r, c, x, y-1)
    st = height(grid, r, c, x, y)

    if st < lt and st < rt and st < up and st < dn:
        return 1
    else:
        return 0

grid = []
for row in range(r):
    heights = map(int, input().split())
    grid += heights

drains = []
for y in range(r):
    for x in range(c):
        state = drain(grid, r, c, x, y)
        drains.append(state)

for y in range(r):
    row = []
    for x in range(c):
        row.append(drains[pidx(x, y, r, c)])
    print(' '.join([str(drain) for drain in row]))
