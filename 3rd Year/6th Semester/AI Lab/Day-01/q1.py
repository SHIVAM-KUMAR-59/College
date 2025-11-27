# Use BFS to get the shortest path, use DFS to get all paths, 0 = wall and 1 = walkable path

def maze_to_graph(maze):
    rows = len(maze)
    cols = len(maze[0])
    graph = {}

    # get valid neighbors (up, down, left, right)
    def neighbors(r, c):
        for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and maze[nr][nc] == 1:
                yield (nr, nc)

    # Build graph
    for r in range(rows):
        for c in range(cols):
            if maze[r][c] == 1:
                graph[(r, c)] = list(neighbors(r, c))

    return graph


# BFS
def bfs(graph, start, goal):
    queue = [(start, [start])]
    visited = set()
    explored = 0

    while queue:
        node, path = queue.pop(0)
        explored += 1
        visited.add(node)

        if node == goal:
            return path, explored

        for neighbor in graph[node]:
            if neighbor not in visited:
                queue.append((neighbor, path + [neighbor]))

    return None, explored


# DFS
def dfs(graph, start, goal):
    stack = [(start, [start])]
    paths = []
    explored = 0

    while stack:
        node, path = stack.pop()
        explored += 1

        if node == goal:
            paths.append(path)
            continue

        for neighbor in graph[node]:
            if neighbor not in path:
                stack.append((neighbor, path + [neighbor]))

    return paths, explored


maze = [
    [1, 0, 1, 1, 1, 1, 0, 1, 1, 1],
    [1, 0, 1, 0, 0, 1, 0, 1, 0, 1],
    [1, 1, 1, 0, 1, 1, 1, 1, 0, 1],
    [0, 0, 1, 0, 1, 0, 0, 1, 0, 1],
    [1, 1, 1, 1, 1, 1, 0, 1, 1, 1],
    [1, 0, 0, 0, 0, 1, 0, 0, 0, 1],
    [1, 1, 1, 1, 0, 1, 1, 1, 0, 1],
    [0, 0, 0, 1, 0, 0, 0, 1, 0, 1],
    [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
]

start = (0, 0)
goal = (9, 9)

graph = maze_to_graph(maze)

bfs_path, bfs_nodes = bfs(graph, start, goal)
dfs_paths, dfs_nodes = dfs(graph, start, goal)

print("Shortest Path using BFS:", bfs_path)
print("Nodes Explored by BFS:", bfs_nodes)
print("\nAll Paths using DFS:")
for p in dfs_paths:
    print(p)
print("Nodes Explored by DFS:", dfs_nodes)
