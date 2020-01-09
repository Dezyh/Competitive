# <= c 

ans = []

t = int(input())
for tc in range(t):

    a, b, c, r = map(int, input().split())

    cs = c-r
    ce = c+r 

    if (a > b):
        tmp = a
        a = b
        b = tmp

    if (ce<a or cs>b):
        print(b-a)
    else:
        print(max(0,cs-a)+max(0,b-ce))

