S, E = 0, 1
DEBUG = False

def overlap(a, b):
    if a[S] == b[S] or a[E] == b[E]:
        return True
    if a[S] > b[S] and a[S] < b[E]:
        return True 
    if a[E] > b[S] and a[E] < b[E]:
        return True 
    if a[S] < b[S] and a[E] > b[E]:
        return True
    if b[S] < a[S] and b[E] > a[E]:
        return True
    return False

def solve(acts):
    overlaps = []

    # find overlaps
    for i in range(len(acts)):
        for j in range(i+1, len(acts)):
            if overlap(acts[i], acts[j]):
                overlaps.append((i, j))
    if DEBUG: print(overlaps)

    c = set()
    j = set()

    for (a, b) in overlaps:

        if DEBUG: print('BEFORE', a, b, c, j)

        # try assign each act (a,b) to c and j
        if a in c:
            j.add(b)
        elif a in j:
            c.add(b)
        elif b in c:
            j.add(a)
        elif b in j:
            c.add(a)
        else:
            c.add(a)
            j.add(b)

        if DEBUG: print('AFTER', a, b, c, j)

        # check if a or b are in both c and j
        # if (a in j and a in c) or (b in j and b in c):
        #     return('IMPOSSIBLE')

        if (a in j and b in j) or (a in c and b in c):
            return('IMPOSSIBLE')

    # create the answer
    ans = ''
    for i in range(len(acts)):
        ans += 'C' if i in c else 'J'

    return(ans)

# -------------------------------------------------------
for t in range(int(input())):
    acts = []
    for n in range(int(input())):
        s, e = map(int, input().split())
        acts.append((s,e))
    ans = solve(acts)
    print('Case #{}: {}'.format(t+1, ans))