# Assignment 4: Uniform Cost Search for Optimal Path
# Objective: Implement Uniform Cost Search for a weighted graph.
# Problem Statement: Given a weighted graph (e.g., a transportation network with travel
# costs), find the minimum-cost path between two nodes.
# Tasks:
# - Represent the graph as an adjacency list.
# - Implement Uniform Cost Search to find the optimal path.
# - Compare it with BFS for unweighted graphs.

import heapq

def uniform_cost_search(graph, start, goal):
    # Priority queue → (cost_so_far, node)
    pq = []
    heapq.heappush(pq, (0, start))

    cost_so_far = {start: 0}
    parent = {start: None}

    while pq:
        current_cost, current_node = heapq.heappop(pq)

        if current_node == goal:
            path = []
            while current_node:
                path.append(current_node)
                current_node = parent[current_node]
            return path[::-1], current_cost

        for neighbor, edge_cost in graph[current_node]:
            new_cost = current_cost + edge_cost

            if neighbor not in cost_so_far or new_cost < cost_so_far[neighbor]:
                cost_so_far[neighbor] = new_cost
                parent[neighbor] = current_node
                heapq.heappush(pq, (new_cost, neighbor))

    return None, float("inf")

graph = {
    'A': [('B', 2), ('C', 5)],
    'B': [('D', 4), ('E', 1)],
    'C': [('E', 2)],
    'D': [('F', 3)],
    'E': [('F', 1)],
    'F': []
}

start = 'A'
goal = 'F'

path, cost = uniform_cost_search(graph, start, goal)

print("Optimal Path:", path)
print("Minimum Cost:", cost)