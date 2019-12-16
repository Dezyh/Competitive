n = int(input())
s = list(input())

def inv(si):
    if si == "W":
        return "B"
    else:
        return "W"
fs = []
i = 0
while i < n-2:
    b = s[i]
    s1 = s[i+1]
    s2 = s[i+2]

    if b == s1 and s1 == s2:
        i+=2
    elif b == s1:
        i+=1
    elif b != s1:
        s[i+1] = inv(s[i+1])
        s[i+2] = inv(s[i+2])
        fs.append(i+1+1)
        i+=1
    
if (s[n-3] == s[n-2] and s[n-2] == s[n-1]):
    print(len(fs))
    if (len(fs) > 0):
        print(*fs)
else:
    if len(s) % 2 == 0:
        print(-1)
    else:
        for i in range(0, n-1, 2):
            fs.append(i+1)
        print(len(fs))
        if (len(fs) > 0):
            print(*fs)