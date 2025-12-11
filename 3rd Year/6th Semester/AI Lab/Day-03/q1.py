# Assignment 3: Search for Treasure using the Best-First Search
# Objective: Use Best-First Search to find a treasure in a grid.
# Problem Statement: The treasure is hidden in a grid, and each cell has a heuristic
# value representing its &quot;closeness&quot; to the treasure. Implement Best-First Search to
# locate the treasure.
# Tasks:
# - Use Manhattan distance as a heuristic.
# - Implement the algorithm to always move to the most promising cell first (minimum heuristic value).
# - Analyze how heuristic choice affects performance.

import heapq

# Manhattan distance heuristic
def manhattan_distance(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


def best_first_search(grid, start, goal):
    rows, cols = len(grid), len(grid[0])
    
    # Priority queue → (heuristic, (x, y))
    pq = []
    heapq.heappush(pq, (manhattan_distance(start, goal), start))
    
    visited = set()
    parent = {start: None}

    while pq:
        h, current = heapq.heappop(pq)
        visited.add(current)

        if current == goal:
            # reconstruct path
            path = []
            while current:
                path.append(current)
                current = parent[current]
            return path[::-1], visited

        x, y = current

        neighbours = [(x+1,y), (x-1,y), (x,y+1), (x,y-1)]

        for nx, ny in neighbours:
            if 0 <= nx < rows and 0 <= ny < cols:
                if (nx, ny) not in visited and grid[nx][ny] != 1:  # 1 is obstacle
                    parent[(nx, ny)] = (x, y)
                    heuristic = manhattan_distance((nx,ny), goal)
                    heapq.heappush(pq, (heuristic, (nx, ny)))

    return None, visited

grid = [
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 0],
    [0, 0, 0, 0, 0]
]

start = (0, 0)
treasure = (4, 4)

path, visited = best_first_search(grid, start, treasure)

print("Path to Treasure:", path)
print("Visited Cells:", visited)