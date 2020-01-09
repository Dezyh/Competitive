
def idp(a,dp,i,k):
    if (i-k) >= 0:
        return min(a[i]+dp[i-1], a[i]+dp[i-k])
    else:
        return a[i]+dp[i-1]

t = int(input())
for tc in range(t):
    n,p,k = map(int, input().split())
    a = [int(x) for x in input().split()]

    a.sort()
    dp = [0]*n

    dp[0] = a[0]
    for i in range(0,k-1):
        dp[i] = a[i]+dp[i-1]
    
    dp[k-1] = a[k-1]

    for i in range(k,n):
        dp[i] = idp(a,dp,i,k)

    bst = 0
    for i in range(n):
        if dp[i] <= p:
            bst = i+1
    print(bst)