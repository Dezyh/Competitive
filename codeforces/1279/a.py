t = int(input())
for tc in range(t):
    r,g,b = [int(x) for x in input().split()]
    print("Yes" if 2*max(r,g,b)-r-g-b<=1 else "No")