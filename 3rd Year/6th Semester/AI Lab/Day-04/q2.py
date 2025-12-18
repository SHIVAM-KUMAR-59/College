# Objective: Use A* Search to find an optimal path for a robot navigating a 2D grid.
# Problem Statement: A robot must move from a start point to a goal in a grid while
# avoiding obstacles.
# Tasks:
# Implement A* with:
#  The Manhattan distance heuristic applies to grids without any diagonal
# movement.
#  The Euclidean distance heuristic is applicable to grids that allow diagonal
# movement.
#  Use a plotting library to visualize the found path.
#  Compare A* with BFS and Uniform Cost Search.

from queue import PriorityQueue, Queue

# Heuristic functions
def manhattan(a, b):
    return abs(a[0]-b[0]) + abs(a[1]-b[1])

# A* Search
def a_star(grid, start, goal, heuristic):
    rows, cols = len(grid), len(grid[0])
    open_set = PriorityQueue()
    open_set.put((0, start))
    
    came_from = {}
    g_score = {start:0}
    nodes_explored = 0
    
    while not open_set.empty():
        _, current = open_set.get()
        nodes_explored += 1
        
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path, nodes_explored
        
        x, y = current
        neighbors = [(x+dx, y+dy) for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]]
        for nx, ny in neighbors:
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny]==0:
                tentative_g = g_score[current] + 1
                if (nx,ny) not in g_score or tentative_g < g_score[(nx,ny)]:
                    g_score[(nx,ny)] = tentative_g
                    f_score = tentative_g + heuristic((nx,ny), goal)
                    open_set.put((f_score, (nx,ny)))
                    came_from[(nx,ny)] = current
    return None, nodes_explored

# BFS
def bfs(grid, start, goal):
    rows, cols = len(grid), len(grid[0])
    queue = Queue()
    queue.put(start)
    visited = {start}
    came_from = {}
    nodes_explored = 0
    
    while not queue.empty():
        current = queue.get()
        nodes_explored += 1
        
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path, nodes_explored
        
        x, y = current
        neighbors = [(x+dx, y+dy) for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]]
        for nx, ny in neighbors:
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny]==0 and (nx,ny) not in visited:
                visited.add((nx,ny))
                queue.put((nx,ny))
                came_from[(nx,ny)] = current
    return None, nodes_explored

# Uniform Cost Search
def ucs(grid, start, goal):
    rows, cols = len(grid), len(grid[0])
    open_set = PriorityQueue()
    open_set.put((0, start))
    
    came_from = {}
    cost_so_far = {start:0}
    nodes_explored = 0
    
    while not open_set.empty():
        current_cost, current = open_set.get()
        nodes_explored += 1
        
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path, nodes_explored
        
        x, y = current
        neighbors = [(x+dx, y+dy) for dx,dy in [(-1,0),(1,0),(0,-1),(0,1)]]
        for nx, ny in neighbors:
            if 0 <= nx < rows and 0 <= ny < cols and grid[nx][ny]==0:
                new_cost = cost_so_far[current] + 1
                if (nx,ny) not in cost_so_far or new_cost < cost_so_far[(nx,ny)]:
                    cost_so_far[(nx,ny)] = new_cost
                    open_set.put((new_cost, (nx,ny)))
                    came_from[(nx,ny)] = current
    return None, nodes_explored

# Print Path
def print_path(grid, path):
    if not path:
        print("No path found")
        return
    for r in range(len(grid)):
        row = ""
        for c in range(len(grid[0])):
            if (r,c) == path[0]:
                row += "S "
            elif (r,c) == path[-1]:
                row += "G "
            elif (r,c) in path:
                row += "* "
            elif grid[r][c] == 1:
                row += "X "
            else:
                row += ". "
        print(row)
    print()

# Main
def main():
    # Hardcoded grid
    grid = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 1, 0, 0, 0],
        [0, 0, 0, 1, 0],
        [0, 0, 0, 0, 0]
    ]
    start = (0, 0)
    goal = (4, 4)
    
    # A* Search
    path, nodes = a_star(grid, start, goal, manhattan)
    print("=== A* Search (Manhattan) ===")
    print_path(grid, path)
    print("Nodes Explored:", nodes, "\n")
    
    # BFS
    path, nodes = bfs(grid, start, goal)
    print("=== BFS ===")
    print_path(grid, path)
    print("Nodes Explored:", nodes, "\n")
    
    # UCS
    path, nodes = ucs(grid, start, goal)
    print("=== Uniform Cost Search ===")
    print_path(grid, path)
    print("Nodes Explored:", nodes)

if __name__ == "__main__":
    main()
