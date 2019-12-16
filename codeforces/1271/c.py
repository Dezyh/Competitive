n, sx, sy = map(int, input().split())

q1s, q2s, q3s, q4s = 0, 0, 0, 0
q12s, q23s, q34s, q41s = 0, 0, 0, 0

for i in range(n):

    x,y = map(int, input().split())

    if x == sx:
        if y > sy:
            #q1,4
            q41s += 1
        else:
            #q2,3
            q23s += 1
    elif y == sy:
        if x > sx:
            # q1,2
            q12s += 1
        else:
            # q3,4
            q34s += 1
    elif x > sx and y > sy:
        # q1
        q1s += 1
        #print("q1")
    elif x > sx and y < sy:
        # q2
        q2s += 1
    elif x < sx and y < sy: 
        # q3
        q3s += 1
    elif x < sx and y > sy:
        # q4
        q4s += 1

ans = []
ans.append((q1s+q2s+q12s, (sx+1, sy)))
ans.append((q2s+q3s+q23s, (sx, sy-1)))
ans.append((q3s+q4s+q34s, (sx-1, sy)))
ans.append((q4s+q1s+q41s, (sx, sy+1)))

a = sorted(ans)[-1]
print(a[0])
print(a[1][0], a[1][1])