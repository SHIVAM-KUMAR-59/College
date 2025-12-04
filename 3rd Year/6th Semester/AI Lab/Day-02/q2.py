# Assignment 2: Route Finder Using Bi-Directional BFS/DFS

from collections import deque

def bidirectional_bfs(graph, start, goal):
    if start == goal:
        return [start], 1

    front_visited = {start: None}
    back_visited = {goal: None}

    front_queue = deque([start])
    back_queue = deque([goal])

    nodes_explored = 0

    meeting_node = None

    while front_queue and back_queue:

        for _ in range(len(front_queue)):
            current = front_queue.popleft()
            nodes_explored += 1

            for neighbor in graph[current]:
                if neighbor not in front_visited:
                    front_visited[neighbor] = current
                    front_queue.append(neighbor)

                    if neighbor in back_visited:
                        meeting_node = neighbor
                        break
            if meeting_node:
                break

        if meeting_node:
            break

        for _ in range(len(back_queue)):
            current = back_queue.popleft()
            nodes_explored += 1

            for neighbor in graph[current]:
                if neighbor not in back_visited:
                    back_visited[neighbor] = current
                    back_queue.append(neighbor)

                    if neighbor in front_visited:
                        meeting_node = neighbor
                        break
            if meeting_node:
                break
    
    if not meeting_node:
        return None, nodes_explored

    path1 = []
    cur = meeting_node
    while cur is not None:
        path1.append(cur)
        cur = front_visited[cur]
    path1.reverse()

    path2 = []
    cur = back_visited[meeting_node]
    while cur is not None:
        path2.append(cur)
        cur = back_visited[cur]

    full_path = path1 + path2

    return full_path, nodes_explored

if __name__ == "__main__":
    graph = {
        'A': ['B','C'],
        'B': ['A','D','E'],
        'C': ['A','F'],
        'D': ['B'],
        'E': ['B','F'],
        'F': ['C','E']
    }

    start = 'A'
    goal = 'F'

    path, explored = bidirectional_bfs(graph, start, goal)

    print("Bi-directional BFS Path:", path)
    print("Nodes Explored:", explored)