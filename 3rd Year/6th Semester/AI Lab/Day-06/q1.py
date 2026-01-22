# Assignment 6: Path Planning for a Robot
# Objective: Use A* Search to find an optimal path for a robot navigating a 2D grid.
# Problem Statement: A robot must move from a start point to a goal in a grid while
# avoiding obstacles.
# Tasks:
# Implement A* with:
# The Manhattan distance heuristic applies to grids without any diagonal
# movement.
# The Euclidean distance heuristic is applicable to grids that allow diagonal
# movement.
# Use a plotting library to visualize the found path.
# Compare A* with BFS and Uniform Cost Search.

import heapq
import math
import matplotlib.pyplot as plt
from collections import deque

# Grid definition (0 = free, 1 = obstacle)
grid = [
    [0,0,0,0,0],
    [0,1,1,1,0],
    [0,0,0,1,0],
    [0,1,0,0,0],
    [0,0,0,0,0]
]

start = (0, 0)
goal = (4, 4)

# Movement definitions
moves_4 = [(1,0), (-1,0), (0,1), (0,-1)]
moves_8 = moves_4 + [(1,1), (1,-1), (-1,1), (-1,-1)]

# Heuristics
def manhattan(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def euclidean(a, b):
    return math.sqrt((a[0] - b[0])**2 + (a[1] - b[1])**2)

# Neighbor generation
def neighbors(node, moves):
    for dx, dy in moves:
        x, y = node[0] + dx, node[1] + dy
        if 0 <= x < len(grid) and 0 <= y < len(grid[0]) and grid[x][y] == 0:
            yield (x, y)

# Path reconstruction
def reconstruct(came_from, node):
    path = []
    while node in came_from:
        path.append(node)
        node = came_from[node]
    path.append(start)
    return path[::-1]

# A* Search
def astar(start, goal, moves, heuristic):
    pq = []
    heapq.heappush(pq, (0, start))
    g_cost = {start: 0}
    came_from = {}

    while pq:
        _, current = heapq.heappop(pq)

        if current == goal:
            return reconstruct(came_from, current)

        for n in neighbors(current, moves):
            new_cost = g_cost[current] + 1
            if n not in g_cost or new_cost < g_cost[n]:
                g_cost[n] = new_cost
                f_cost = new_cost + heuristic(n, goal)
                heapq.heappush(pq, (f_cost, n))
                came_from[n] = current
    return []

# Breadth First Search
def bfs(start, goal):
    q = deque([start])
    visited = {start}
    came_from = {}

    while q:
        current = q.popleft()
        if current == goal:
            return reconstruct(came_from, current)

        for n in neighbors(current, moves_4):
            if n not in visited:
                visited.add(n)
                came_from[n] = current
                q.append(n)
    return []

# Uniform Cost Search
def ucs(start, goal):
    pq = []
    heapq.heappush(pq, (0, start))
    cost = {start: 0}
    came_from = {}

    while pq:
        current_cost, node = heapq.heappop(pq)
        if node == goal:
            return reconstruct(came_from, node)

        for n in neighbors(node, moves_4):
            new_cost = current_cost + 1
            if n not in cost or new_cost < cost[n]:
                cost[n] = new_cost
                came_from[n] = node
                heapq.heappush(pq, (new_cost, n))
    return []

# Run algorithms
path_astar_manhattan = astar(start, goal, moves_4, manhattan)
path_astar_euclidean = astar(start, goal, moves_8, euclidean)
path_bfs = bfs(start, goal)
path_ucs = ucs(start, goal)

# Comparison output
print("Path Length Comparison")
print("----------------------")
print("A* (Manhattan):", len(path_astar_manhattan))
print("A* (Euclidean):", len(path_astar_euclidean))
print("BFS:", len(path_bfs))
print("UCS:", len(path_ucs))

# Visualization
plt.figure(figsize=(6,6))
plt.imshow(grid, cmap="gray_r")

def plot_path(path, color, label):
    if path:
        x = [p[1] for p in path]
        y = [p[0] for p in path]
        plt.plot(x, y, color, label=label, linewidth=2)

plot_path(path_astar_manhattan, 'r-', 'A* Manhattan')
plot_path(path_astar_euclidean, 'b--', 'A* Euclidean')
plot_path(path_bfs, 'g-.', 'BFS')
plot_path(path_ucs, 'y:', 'UCS')

plt.scatter(start[1], start[0], c='green', s=100, label="Start")
plt.scatter(goal[1], goal[0], c='blue', s=100, label="Goal")

plt.legend()
plt.title("Path Planning using A*, BFS and UCS")
plt.show()
