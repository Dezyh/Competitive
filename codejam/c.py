MINUTES = 60*24
START, END, INDEX, PERSON = 0, 1, 2, 3

def solve():
    acts = []
    for i in range(int(input())):
        acts.append([int(x) for x in input().split()] + [i])
    acts.sort()

    c, j = [0]*MINUTES, [0]*MINUTES
    for act in acts:
        s, e, d = act[START], act[END], act[END]-act[START]
        if c[s:e] == [0]*d:
            c[s:e] = [1]*d
            act.append("C")
        elif j[s:e] == [0]*d:
            j[s:e] = [1]*d
            act.append("J")
        else:
            return "IMPOSSIBLE"
 
    acts.sort(key=lambda act: act[INDEX])
    answer = ""
    for act in acts:
        answer += act[PERSON]
    return answer

for t in range(int(input())):
    print('Case #{}: {}'.format(t+1, solve()))