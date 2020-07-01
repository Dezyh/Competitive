from math import sqrt

x, y, x1, y1, x2, y2 = map(int, input().split())

X, Y = 0, 1

if x >= x1 and x <= x2:
    if y > y2:
        cp = (x,y2)
    else:
        cp = (x,y1)
elif y >= y1 and y <= y2:
    if (x > x2):
        cp = (x2,y)
    else:
        cp = (x1,y)
else:
    if x < x1 and y < y1:
        cp = (x1,y1)
    elif x < x1 and y > y2:
        cp = (x1,y2)
    elif x > x2 and y < y1:
        cp = (x2,y1)
    else:
        cp = (x2,y2)

dst = sqrt((cp[X]-x)**2 + (cp[Y]-y)**2)

print('{0:.3f}'.format(dst))
