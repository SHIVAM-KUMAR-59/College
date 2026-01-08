# Objective: Solve the 8-puzzle using A* search.
# Problem Statement: The 8-puzzle involves sliding tiles to achieve a goal state. Use A*
# to solve it.
# Tasks:
# Define heuristic functions:
#  H1: Number of misplaced tiles.
#  H2: Sum of Manhattan distances of all tiles from their goal positions.
#  Implement A* with both heuristics.
#  Compare the performance of the two heuristics in terms of the number of nodes
# explored and solution depth.

# Goal state
GOAL = (
    (1, 2, 3),
    (4, 5, 6),
    (7, 8, 0)
)

# Initial state
START = (
    (1, 2, 3),
    (4, 0, 6),
    (7, 5, 8)
)

# Heuristic 1
# Number of misplaced tiles
def h1_misplaced(state):
    count = 0
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0 and state[i][j] != GOAL[i][j]:
                count += 1
    return count

# Heuristic 2
# Manhattan distance
def h2_manhattan(state):
    distance = 0
    for i in range(3):
        for j in range(3):
            value = state[i][j]
            if value != 0:
                goal_x = (value - 1) // 3
                goal_y = (value - 1) % 3
                distance += abs(i - goal_x) + abs(j - goal_y)
    return distance

# Helper Functions
def find_blank(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j

def get_neighbors(state):
    neighbors = []
    x, y = find_blank(state)

    moves = [(-1,0), (1,0), (0,-1), (0,1)]

    for dx, dy in moves:
        nx, ny = x + dx, y + dy
        if 0 <= nx < 3 and 0 <= ny < 3:
            new_state = [list(row) for row in state]
            new_state[x][y], new_state[nx][ny] = new_state[nx][ny], new_state[x][y]
            neighbors.append(tuple(tuple(row) for row in new_state))

    return neighbors

# A* Algo
def astar(start, heuristic):
    open_list = [(heuristic(start), 0, start)]
    visited = set()
    nodes_explored = 0

    while open_list:
        open_list.sort()          # Sort by f = g + h
        f, g, current = open_list.pop(0)
        nodes_explored += 1

        if current == GOAL:
            return nodes_explored, g

        visited.add(current)

        for neighbor in get_neighbors(current):
            if neighbor not in visited:
                h = heuristic(neighbor)
                open_list.append((g + 1 + h, g + 1, neighbor))

    return None

print("Using Heuristic H1 (Misplaced Tiles)")
nodes1, depth1 = astar(START, h1_misplaced)
print("Nodes explored:", nodes1)
print("Solution depth:", depth1)

print("\nUsing Heuristic H2 (Manhattan Distance)")
nodes2, depth2 = astar(START, h2_manhattan)
print("Nodes explored:", nodes2)
print("Solution depth:", depth2)

print("\nComparison:")
if nodes2 < nodes1:
    print("Manhattan Distance heuristic is more efficient.")
else:
    print("Both heuristics perform similarly.")
