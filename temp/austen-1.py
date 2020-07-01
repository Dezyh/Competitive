def palidrome(n, array):
    seen = dict()
    for i in range(n):
        if array[i] in seen:
            if i - seen[array[i]] > 1:
                return True
        else:
            seen[array[i]] = i
    
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = "YES" if palidrome(n, arr) else "NO"
    print(ans)
