# AI Planner Using A for Task Scheduling*
# Objective: Use A* Search to optimize task scheduling.
# Problem Statement: A set of tasks with dependencies and durations needs to be
# scheduled to minimize total time.
# Tasks:
# - Represent tasks and dependencies as a directed graph.
# - Use A* Search when the heuristic estimates the remaining tasks&#39; duration.
# - Compare results with a greedy algorithm.

import heapq
 
tasks = {
    'A': 3,
    'B': 2,
    'C': 4,
    'D': 1
}
 
dependencies = {
    'A': [],
    'B': [],
    'C': ['A', 'B'],
    'D': ['C']
}
 
all_tasks = set(tasks.keys())
 
def get_available_tasks(completed):
    available = []
    for task in all_tasks:
        if task not in completed:
            if all(dep in completed for dep in dependencies[task]):
                available.append(task)
    return available
 
def heuristic(completed):
    remaining = all_tasks - completed
    return sum(tasks[t] for t in remaining)
 
def astar_scheduler():
    pq = []
    heapq.heappush(pq, (0, frozenset(), 0, []))
    visited = set()
 
    while pq:
        f, completed, time, path = heapq.heappop(pq)
 
        if completed in visited:
            continue
        visited.add(completed)
 
        if completed == all_tasks:
            return time, path
 
        available = get_available_tasks(completed)
 
        for task in available:
            new_completed = completed | {task}
            new_time = time + tasks[task]
            h = heuristic(new_completed)
            heapq.heappush(pq, (new_time + h, new_completed, new_time, path + [task]))
 
    return None
 
def greedy_scheduler():
    completed = set()
    time = 0
    order = []
 
    while len(completed) < len(tasks):
        available = get_available_tasks(completed)
        available.sort(key=lambda x: tasks[x])
        chosen = available[0]
 
        completed.add(chosen)
        order.append(chosen)
        time += tasks[chosen]
 
    return time, order
 
print("A* Scheduling:")
astar_result = astar_scheduler()
print("Total Time:", astar_result[0])
print("Order:", astar_result[1])
 
print("\nGreedy Scheduling:")
greedy_result = greedy_scheduler()
print("Total Time:", greedy_result[0])
print("Order:", greedy_result[1])
 