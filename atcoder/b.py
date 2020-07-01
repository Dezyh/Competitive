def ceildiv(a, b):
    return -(-a // b)

h, w = map(int, input().split())

if (h==1 or w==1):
    print(1)
else:
    r0 = ceildiv(w,2)
    r1 = w//2
    r0s = ceildiv(h,2)
    r1s = h//2



    print(r0*r0s + r1*r1s)