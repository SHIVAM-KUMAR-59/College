import random
import math

START = (0, 0, 0)
TARGET = (1000, 1000, 0)
ALTITUDE_LIMITS = (100, 5000) 
ENEMY_ZONE = {"center": (500, 500, 500), "radius": 200}

POP_SIZE = 100
WAYPOINTS_COUNT = 5 
GENERATIONS = 200
MUTATION_RATE = 0.1

def calculate_distance(p1, p2):
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(p1, p2)))

def fitness(trajectory):
    """Lower is better (Cost function)"""
    full_path = [START] + trajectory + [TARGET]
    fuel_cost = 0
    penalty = 0
    
    for i in range(len(full_path) - 1):
        p1, p2 = full_path[i], full_path[i+1]
        dist = calculate_distance(p1, p2)
        fuel_cost += dist
        
        mid_x = (p1[0] + p2[0]) / 2
        mid_y = (p1[1] + p2[1]) / 2
        mid_z = (p1[2] + p2[2]) / 2
        if calculate_distance((mid_x, mid_y, mid_z), ENEMY_ZONE["center"]) < ENEMY_ZONE["radius"]:
            penalty += 5000
            
        if not (ALTITUDE_LIMITS[0] < p2[2] < ALTITUDE_LIMITS[1]) and i < len(full_path)-2:
            penalty += 1000
            
    return fuel_cost + penalty

population = []
for _ in range(POP_SIZE):
    indiv = [(random.randint(0, 1000), random.randint(0, 1000), random.randint(100, 1000)) 
             for _ in range(WAYPOINTS_COUNT)]
    population.append(indiv)

for gen in range(GENERATIONS):
    population.sort(key=lambda x: fitness(x))
    
   
    next_gen = population[:20]
    
    while len(next_gen) < POP_SIZE:
        
        parent1 = random.choice(population[:50])
        parent2 = random.choice(population[:50])
        
       
        cp = random.randint(1, WAYPOINTS_COUNT - 1)
        child = parent1[:cp] + parent2[cp:]
        
        if random.random() < MUTATION_RATE:
            idx = random.randint(0, WAYPOINTS_COUNT - 1)
            child[idx] = (child[idx][0] + random.randint(-50, 50),
                          child[idx][1] + random.randint(-50, 50),
                          child[idx][2] + random.randint(-50, 50))
        
        next_gen.append(child)
    
    population = next_gen

best_path = population[0]
print(f"Optimal Trajectory: {best_path}")
print(f"Minimum Cost: {fitness(best_path)}")