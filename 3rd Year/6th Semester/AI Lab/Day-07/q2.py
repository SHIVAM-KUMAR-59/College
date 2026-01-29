# Simulated annealing (SA)

import math
import random

def f(x):
    return -x**2 + 10

def simulated_annealing(start):
    current = start
    temperature = 100
    cooling_rate = 0.95

    while temperature > 0.1:
        neighbor = current + random.choice([-1, 1])

        if -10 <= neighbor <= 10:
            delta = f(neighbor) - f(current)

            if delta > 0:
                current = neighbor
            else:
                probability = math.exp(delta / temperature)
                if random.random() < probability:
                    current = neighbor

        temperature *= cooling_rate

    return current, f(current)

start = random.randint(-10, 10)
result = simulated_annealing(start)
print("Simulated Annealing → Start:", start, "Result:", result)