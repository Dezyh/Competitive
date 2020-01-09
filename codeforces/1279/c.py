t = int(input())
for tc in range(t):
    n, m = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    loc = dict()
    for i in range(n):
        loc[a[i]] = i
    t = 0
    p = 0
    j = 0
    while j < m:
        d = loc[b[j]]-p
        t += 2*d+1
        j += 1
        tp = 1
        while j < m and (loc[b[j]]-p) < d:
            tp += 1
            t += 1
            j += 1
        p += tp
    print(t)