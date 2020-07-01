from collections import deque

a = deque([i for i in range(10)])
b = deque([i for i in range(10)])
c = deque([i for i in range(100000000)])

#a += b
a += c
