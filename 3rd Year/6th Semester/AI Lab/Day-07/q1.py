# Steepest, Stochastic hill climbing (HC)

import random

def f(x):
    return -x**2 + 10

def steepest_hill_climbing(start):
    current = start

    while True:
        neighbors = [current - 1, current + 1]
        neighbors = [n for n in neighbors if -10 <= n <= 10]

        best_neighbor = max(neighbors, key=f)

        if f(best_neighbor) <= f(current):
            break

        current = best_neighbor

    return current, f(current)

start = random.randint(-10, 10)
result = steepest_hill_climbing(start)
print("Steepest HC → Start:", start, "Result:", result)

def stochastic_hill_climbing(start):
    current = start

    while True:
        neighbors = [current - 1, current + 1]
        neighbors = [n for n in neighbors if -10 <= n <= 10 and f(n) > f(current)]

        if not neighbors:
            break

        current = random.choice(neighbors)

    return current, f(current)

start = random.randint(-10, 10)
result = stochastic_hill_climbing(start)
print("Stochastic HC → Start:", start, "Result:", result)
