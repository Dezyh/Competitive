n = int(input())
statements = [tuple(map(int, input().split())) for x in range(n)]

best = -1

for i in range(n+1):
    truths = 0
    for statement in statements:
        if i >= statement[0] and i <= statement[1]:
            truths += 1
    if truths == i:
        best = max(best, truths)

print(best)