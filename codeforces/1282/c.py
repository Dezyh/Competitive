E, H = 0, 1
M, D = 0, 1
t = int(input())
    
for tc in range(t):

    n, T, a, b = [int(x) for x in input().split()]
    qd = [int(x) for x in input().split()]
    qm = [int(x) for x in input().split()]
    qs = sorted(zip(qm,qd))
    
    bst = 0
    m = [0,0]
    r = [n-sum(qd),sum(qd)]

    for q in qs:

        qt = q[M]-1
        mt = a*m[E]+b*m[H]
        rt = qt-mt
        re = max(0,min(r[E], rt // a))
        rh = max(0,min(r[H], (rt-a*re) // b))
        if rt >= 0: bst = max(bst, m[E]+m[H]+re+rh)

        if q[D]==E:
            m[E]+=1
            r[E]-=1
        else:
            m[H]+=1
            r[H]-=1

        qt = q[M]
        mt = a*m[E]+b*m[H]
        rt = qt-mt
        re = max(0,min(r[E], rt // a))
        rh = max(0,min(r[H], (rt-a*re) // b))
        if rt >= 0: bst = max(bst, m[E]+m[H]+re+rh)

    mt = a*m[E]+b*m[H]
    rt = T-mt
    re = max(0,min(r[E], rt // a))
    rh = max(0,min(r[H], (rt-a*re) // b))
    if rt >= 0: 
        bst = max(bst, m[E]+m[H]+re+rh)

    print(bst)