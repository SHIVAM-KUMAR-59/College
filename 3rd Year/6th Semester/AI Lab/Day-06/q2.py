# Assignment 7: Game AI Using Search Algorithms
# Objective: Implement AI to solve a simple turn-based game.
# Problem Statement: Design an AI agent to play a game (e.g., Tic-Tac-Toe or Snake
# and Ladder) using search algorithms.

# Tasks:
# Use BFS and DFS for exploring game states.
# Implement A* Search with a heuristic function to improve efficiency.
# Compare search strategies for different game board configurations.

from collections import deque
import heapq

# Winning combinations
WINS = [
    (0,1,2),(3,4,5),(6,7,8),
    (0,3,6),(1,4,7),(2,5,8),
    (0,4,8),(2,4,6)
]

# Initial empty board
START_STATE = "_________"


def is_winner(state, player):
    for a, b, c in WINS:
        if state[a] == state[b] == state[c] == player:
            return True
    return False

def is_terminal(state):
    return is_winner(state, "X") or is_winner(state, "O") or "_" not in state

def next_states(state, player):
    states = []
    for i in range(9):
        if state[i] == "_":
            states.append(state[:i] + player + state[i+1:])
    return states

def bfs(start):
    queue = deque([(start, "X")])
    visited = set([start])
    nodes = 0

    while queue:
        state, player = queue.popleft()
        nodes += 1

        if is_winner(state, "X"):
            return True, nodes

        if is_terminal(state):
            continue

        next_player = "O" if player == "X" else "X"

        for nxt in next_states(state, player):
            if nxt not in visited:
                visited.add(nxt)
                queue.append((nxt, next_player))

    return False, nodes

def dfs(start):
    stack = [(start, "X")]
    visited = set()
    nodes = 0

    while stack:
        state, player = stack.pop()
        nodes += 1

        if is_winner(state, "X"):
            return True, nodes

        if is_terminal(state):
            continue

        visited.add(state)
        next_player = "O" if player == "X" else "X"

        for nxt in next_states(state, player):
            if nxt not in visited:
                stack.append((nxt, next_player))

    return False, nodes

def heuristic(state):
    """
    Heuristic: number of winning lines still open for X
    Higher value = better state for X
    """
    score = 0
    for a, b, c in WINS:
        line = [state[a], state[b], state[c]]
        if "O" not in line:
            score += line.count("X")
    return score

def astar(start):
    pq = []
    heapq.heappush(pq, (-heuristic(start), 0, start, "X"))
    visited = {}
    nodes = 0

    while pq:
        _, cost, state, player = heapq.heappop(pq)
        nodes += 1

        if is_winner(state, "X"):
            return True, nodes

        if is_terminal(state):
            continue

        if state in visited and visited[state] <= cost:
            continue

        visited[state] = cost
        next_player = "O" if player == "X" else "X"

        for nxt in next_states(state, player):
            g = cost + 1
            f = g - heuristic(nxt)
            heapq.heappush(pq, (f, g, nxt, next_player))

    return False, nodes

if __name__ == "__main__":
    bfs_result, bfs_nodes = bfs(START_STATE)
    dfs_result, dfs_nodes = dfs(START_STATE)
    astar_result, astar_nodes = astar(START_STATE)

    print("===== GAME AI SEARCH COMPARISON =====")
    print(f"BFS  -> Win Found: {bfs_result}, Nodes Explored: {bfs_nodes}")
    print(f"DFS  -> Win Found: {dfs_result}, Nodes Explored: {dfs_nodes}")
    print(f"A*   -> Win Found: {astar_result}, Nodes Explored: {astar_nodes}")