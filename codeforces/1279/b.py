t = int(input())
for tc in range(t):
    n,s = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    m = 0
    mi = 0
    i = 0
    while i < n and s >= 0:
        s -= a[i]
        if a[i] > m:
            m = a[i]
            mi = i 
        i += 1
    if i == n and s >= 0:
        print(0)
    else:
        print(mi+1)