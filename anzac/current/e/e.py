from itertools import combinations

def options(rem):

    rolls = dict()
    for i in range(2, 13):
        rolls[i] = []

    for combination in (x for l in range(1, len(rem)+1) for x in combinations(rem, l)):

        x = sum(combination)

        if x >= 2 and x <= 12:
            rolls[x].append(combination)
    
    return rolls


rolls = 36
roll_pr = {
    2: 1,
    3: 2,
    4: 3,
    5: 4,
    6: 5,
    7: 6,
    8: 5,
    9: 4,
    10: 3, 
    11: 2, 
    12: 1
}

def play(d, choices, eliminated):
    
    if not choices:
        return (eliminated, ''.join(d))
    
    for choice in choices:
        



d0, a0, b0 = input().split()
d = map(int, list(d0))
a = int(a0)
b = int(b0)

roll = a+b
all_options = options(d)

choices = all_options[roll]

if not choices:
    x = (-1, ''.join(d))
else:
    x = play(d, choices)

print(opts)