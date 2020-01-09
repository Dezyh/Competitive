t = int(input())
for tc in range(t):
    n,p,k = map(int, input().split())
    a = [int(x) for x in input().split()]

    a.sort()
    dp = [0]*n

    dp[0] = a[0]
    dp[1] = a[1]

    for i in range(2,n):
        dp[i] = min(a[i]+dp[i-1], a[i]+dp[i-2])
    
    i=0
    while (i<n and dp[i]<=p):
        i+=1
    
    print(i)