n, e = 7, 9

g = {
    0: [1, 2],
    1: [2, 3],
    2: [3, 4],
    3: [5],
    4: [6],
    5: [6],
    6: [],
}

v = [False] * n

def dfs(graph, node, visited):
    visited[node] = True
    for child in graph[node]:
        if not visited[child]:
            dfs(graph, child, visited)