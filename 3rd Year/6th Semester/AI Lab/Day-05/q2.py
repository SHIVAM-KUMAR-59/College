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

import heapq

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

def uniform_cost_search(start):
    pq = []                      # priority queue (cost, state)
    heapq.heappush(pq, (0, start))
    visited = set()
    nodes_explored = 0

    while pq:
        cost, current = heapq.heappop(pq)
        nodes_explored += 1

        if current == GOAL:
            return nodes_explored, cost

        if current in visited:
            continue

        visited.add(current)

        for neighbor in get_neighbors(current):
            if neighbor not in visited:
                heapq.heappush(pq, (cost + 1, neighbor))

    return None

print("Using Uniform Cost Search")
nodes, depth = uniform_cost_search(START)
print("Nodes explored:", nodes)
print("Solution depth:", depth)