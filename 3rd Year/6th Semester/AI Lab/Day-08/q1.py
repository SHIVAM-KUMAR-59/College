# Navigation with Multiple Goals
# Objective: Solve a problem where multiple goals exist using search algorithms.
# Problem Statement: A robot in a grid needs to collect items (goals) before reaching an
# exit. Each goal has a different priority or cost.

# Tasks:
# - Use BFS/DFS for simpler scenarios (unweighted goals).
# - Implement A* or Uniform Cost Search for weighted scenarios.
# - Analyze the trade-offs between path length and goal priority.

from collections import deque
import heapq
 
grid = [
    ['S', '.', 'G'],
    ['.', '#', '.'],
    ['G', '.', 'E']
]
 
rows = len(grid)
cols = len(grid[0])
 
directions = [(-1,0),(1,0),(0,-1),(0,1)]
 
goal_costs = {
    (0,2): 5,
    (2,0): 2
}
 
for i in range(rows):
    for j in range(cols):
        if grid[i][j] == 'S':
            start = (i,j)
        elif grid[i][j] == 'E':
            exit_pos = (i,j)
 
goals = set(goal_costs.keys())

def get_neighbors(pos):
    neighbors = []
    for dx, dy in directions:
        nx, ny = pos[0] + dx, pos[1] + dy
        if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny] != '#':
            neighbors.append((nx, ny))
    return neighbors
 
def bfs():
    queue = deque()
    queue.append((start, frozenset(), []))
    visited = set()
 
    while queue:
        pos, collected, path = queue.popleft()
 
        if (pos, collected) in visited:
            continue
        visited.add((pos, collected))
 
       
        if pos in goals:
            collected = collected | {pos}
 
       
        if collected == goals and pos == exit_pos:
            return path + [pos]
 
        for neighbor in get_neighbors(pos):
            queue.append((neighbor, collected, path + [pos]))
 
    return None
 
def heuristic(pos, collected):
    remaining = goals - collected
 
    if not remaining:
        return abs(pos[0] - exit_pos[0]) + abs(pos[1] - exit_pos[1])
    return min(abs(pos[0]-g[0]) + abs(pos[1]-g[1]) for g in remaining)
 
def astar():
    pq = []
    heapq.heappush(pq, (0, start, frozenset(), 0, []))
    visited = set()
 
    while pq:
        f, pos, collected, cost, path = heapq.heappop(pq)
 
        if (pos, collected) in visited:
            continue
        visited.add((pos, collected))
 
       
        if pos in goals and pos not in collected:
            cost += goal_costs[pos]
            collected = collected | {pos}
 
       
        if collected == goals and pos == exit_pos:
            return path + [pos], cost
 
        for neighbor in get_neighbors(pos):
            new_cost = cost + 1  
            h = heuristic(neighbor, collected)
            heapq.heappush(pq, (new_cost + h, neighbor, collected, new_cost, path + [pos]))
 
    return None
 
print("===== PART 1: BFS (Unweighted) =====")
bfs_result = bfs()
print("Path:", bfs_result)
print("Steps:", len(bfs_result)-1 if bfs_result else "No Path")
 
print("\n===== PART 2: A* (Weighted Goals) =====")
astar_result = astar()
if astar_result:
    path, cost = astar_result
    print("Path:", path)
    print("Total Cost:", cost)
else:
    print("No Path Found")