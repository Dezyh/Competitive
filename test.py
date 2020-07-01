from itertools import permutations

target = 42
cards = [44,6,1,49,47]

def solve(cards, target, curr=0):
    if curr == target:
        return True

    if not cards:
        return False

    card = cards[0]
    remaining = cards[1:]

    a = solve(remaining, target, curr+card)
    b = solve(remaining, target, curr-card)
    c = solve(remaining, target, curr*card)

    return a or b or c

for card in list(permutations(cards)):
    start = cards[0]
    remaining = cards[1:]

    if solve(remaining, target, start):
        print('Yes')
        exit()

print('No')