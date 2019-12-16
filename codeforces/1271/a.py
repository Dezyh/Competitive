# a ties
# b scarves
# c vests
# d jackets

# a + d = e
# b + c + d = f

# 11 * 6 + 9 * 4

a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())

m = 0

if e > f:
    m += e * min(a, d)
    d -= min(a, d)
    m += f * min(b, c, d)
else:
    m += f * min(b, c, d)
    d -= min(b, c, d)
    m += e * min(a, d)

print(m)