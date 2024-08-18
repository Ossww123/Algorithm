N = int(input())
populations = list(map(int, input().split()))

edges = [[0] * (N+1) for _ in range(N+1)]
for i in range(1, N+1):
    temp = list(map(int, input().split()))
    for j in range(temp[0]):
        edges[i][temp[j+1]] = 1

cities = [i for i in range(1, N+1)]
min_diff = 0xFFFF

def dfs(cities):
    stk = [cities[0]]
    visited = []
    population = 0
    
    while stk:
        start = stk.pop()
        if start not in visited:
            population += populations[start-1]
        visited.append(start)
        
        for idx in range(1, N+1):
            if edges[start][idx] == 1 and idx not in visited and idx in cities:
                stk.append(idx)
    # print(cities, visited)
    
    if set(cities) != set(visited):
        return False
    else:
        return population

def cal_diff(A_cities):
    global min_diff
    
    B_cities = list(set(cities) - set(A_cities))
    # print(A_cities, B_cities)
    
    A_population = dfs(A_cities)
    B_population = dfs(B_cities)
    # print(A_population, B_population)
    
    if A_population and B_population:
        diff = abs(A_population - B_population)
        if diff < min_diff:
            min_diff = diff
    

def permutation(idx = 0, A_cities = [N]):
    if idx == N-1:
        if not len(A_cities) == N:
            cal_diff(A_cities)
        return
    
    for j in range(2):
        if j == 0:
            A_cities.append(cities[idx])
            permutation(idx+1, A_cities)
            A_cities.pop()
        else:
            permutation(idx+1, A_cities)
    
                
permutation()
if min_diff > 0xFFFE:
    min_diff = -1
print(min_diff)