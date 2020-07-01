even = 0
odd = 1

def greatest_odd_sum(n, array):
    
    dp = [[0 for _ in range(2)] for _ in range(n)] # dp[0][even]
    
    if even(array[0]):
        dp[0][even] = array[0]
    else:
        dp[0][odd] = array[0]
        
    for i in range(1, n):
        cur = array[i]
        if even(cur):
            dp[i][odd]  =  max(dp[i-1][odd] + cur, dp[i-1][odd])
            dp[i][even] =  max(dp[i-1][even] + cur, cur, dp[i-1][even])
        else:
            dp[i][odd]  =  max(dp[i-1][even] + cur, cur, dp[i-1][odd]) # s
            dp[i][even] =  max(dp[i-1][odd] + cur, dp[i-1][even])
    
    return dp[n-1][odd]

greatest_odd_sum(3, [-2,-1,-4])