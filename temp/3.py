def topological(current, visited, graph, stack=[]):
    visited[current] = True
    for adjacent in graph[current]:
        print(current, adjacent)
        if not visited[adjacent]:
            topological(adjacent, visited, graph, stack)

        stack.insert(0, current)
    return stack

n, m = map(int, input().split())
g = [[] for x in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)

v = [False]*(n+1)
ret = topological(0, v, g)

print(ret)