def subsolve(m, p, i=0, j=0, d=0):
    ans = []

    while i<len(m) and j<len(p) and (m[i] == p[j] and m[i] != '*'):
        i+=1
        j+=1

    if i==len(m)-1 and j==len(p)-1:
        return [(m,p)] + ans

    if i>=len(m) or j>=len(p):
        # print("END")
        return []

    # print(d)
    # print(i, m)
    # print(j, p)
    # print()

    if m[i]=='*' and p[j]=='*':
        mb = m[:]
        mb.insert(i+1, '|')
        pb = p[:]
        pb.insert(j+1, '|')
        ans += subsolve(mb, pb, i+2, j+2, d+1)
        ans += subsolve(m, p, i, j+1, d+1)
        ans += subsolve(m, p, i+1, j, d+1)

    elif m[i]=='*':
        mb = m[:]
        mb.insert(i+1, '|')
        pb = p[:]
        pb.insert(j+1, '|')
        ans += subsolve(mb, pb, i+2,  j+2, d+1)
        ans += subsolve(m, p, i+1, j, d+1)

    elif p[j]=='*':
        mb = m[:]
        mb.insert(i+1, '|')
        pb = p[:]
        pb.insert(j+1, '|')
        ans += subsolve(mb, pb, i+2, j+2, d+1)
        ans += subsolve(m, p, i+1, j, d+1)

    if i==len(m) and j==len(p):
        return [m] + ans
    else:
        return ans
      

def solve(t, n, patterns):
    for i in range(n):
        patterns[i] = patterns[i].replace("**", "*")
    patterns.sort(key=lambda pattern: len(pattern))
    
    matches = set()
    matches.add(patterns.pop())

    while(patterns):
        pattern = patterns.pop()
        for match in matches:
            matches.remove(match)
            new_matches = subsolve(list(match), list(pattern))
            for new_match in new_matches:
                matches.add(new_match)
    
    # print matches[0].replace('*','')

[print(x) for x in subsolve(list('*HELLO*'), list('H*O'))]

# for t in range(1, int(input())+1):
#     n = int(input())
#     p = [input() for i in range(n)]
#     solve(t, n, p)