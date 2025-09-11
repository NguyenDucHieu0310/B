import random as rd
import math


n = 20
population_size = 50
mutation_rate = 0.1
crossover_rate = 0.8
population = [[rd.randint(0, n - 1) for _ in range(n)] for _ in range(population_size)]

def get_violations(individual):
    v = 0
    for i in range(n):
        for j in range(i + 1, n):
            if individual[i] == individual[j] or individual[i] + i == individual[j] + j or individual[i] - i == individual[j] - j:
                v += 1
    return v

def get_fitness(individual):
    return math.exp(-get_violations(individual))

def selection():
    global population
    fitness_scores = [get_fitness(ind) for ind in population]
    return rd.choices(population, weights=fitness_scores, k=2)

def crossover(parent1, parent2):
    if rd.random() < crossover_rate:
        i = rd.randint(0, n - 1)
        child1 = parent1[:i] + parent2[i:]
        child2 = parent2[:i] + parent1[i:]
        return child1, child2
    return parent1, parent2

def mutation(individual):
    if rd.random() < mutation_rate:
        i = rd.randint(0, n - 1)
        j = rd.randint(0, n - 1)
        individual[i], individual[j] = individual[j], individual[i]

def genetic_algorithm(max_iter=1000):
    global population
    best_individual = None
    best_violations = 1e9
    
    for i in range(max_iter):
        new_population = []
        
        for _ in range(population_size // 2):
            parent1, parent2 = selection()
            child1, child2 = crossover(parent1, parent2)
            mutation(child1)
            mutation(child2)
            new_population.extend([child1, child2])
        
        population = new_population

        for ind in population:
            violations = get_violations(ind)
            if violations < best_violations:
                best_violations = violations
                best_individual = ind
                if best_violations == 0:
                    return best_individual

        print(f'Step {i + 1}: Best violations = {best_violations}')

    return best_individual

solution = genetic_algorithm()
print("Solution found:", solution)
