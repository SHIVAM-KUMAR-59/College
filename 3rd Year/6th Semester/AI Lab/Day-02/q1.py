# Assignment-1: Maze Solver using BFS and DFS

from collections import deque

DIRS = [(1,0), (-1,0), (0,1), (0,-1)]


def bfs(maze, start, goal):
    rows, cols = len(maze), len(maze[0])
    queue = deque([start])
    visited = set([start])
    parent = {start: None}
    nodes_explored = 0

    while queue:
        node = queue.popleft()
        nodes_explored += 1
        
        if node == goal:
            break
        
        r, c = node
        for dr, dc in DIRS:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and maze[nr][nc] == 1:
                if (nr, nc) not in visited:
                    visited.add((nr, nc))
                    parent[(nr, nc)] = node
                    queue.append((nr, nc))

    path = []
    if goal in parent:
        cur = goal
        while cur:
            path.append(cur)
            cur = parent[cur]
        path.reverse()

    return path, nodes_explored


def dfs(maze, start, goal):
    rows, cols = len(maze), len(maze[0])
    stack = [start]
    visited = set([start])
    parent = {start: None}
    nodes_explored = 0

    while stack:
        node = stack.pop()
        nodes_explored += 1

        if node == goal:
            break
        
        r, c = node
        for dr, dc in DIRS:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and maze[nr][nc] == 1:
                if (nr, nc) not in visited:
                    visited.add((nr, nc))
                    parent[(nr, nc)] = node
                    stack.append((nr, nc))

    path = []
    if goal in parent:
        cur = goal
        while cur:
            path.append(cur)
            cur = parent[cur]
        path.reverse()

    return path, nodes_explored


if __name__ == "__main__":
    maze = [
        [1,1,0,1],
        [0,1,1,1],
        [1,1,0,1],
        [1,0,1,1]
    ]

    start = (0,0)
    goal = (3,3)

    bfs_path, bfs_nodes = bfs(maze, start, goal)
    dfs_path, dfs_nodes = dfs(maze, start, goal)

    print("BFS Shortest Path:", bfs_path)
    print("BFS Nodes Explored:", bfs_nodes)

    print("\nDFS Path:", dfs_path)
    print("DFS Nodes Explored:", dfs_nodes)