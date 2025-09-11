from ortools.sat.python import cp_model

def input_data():
    n = int(input())
    c = [[0]*n for _ in range(n)]
    for i in range(n):
        c[i] = list(map(int, input().split()))

    return n, c

def solve():
    n, c = input_data()
    x = [[0]*n for _ in range(n)]

    model = cp_model.CpModel()
    solver = cp_model.CpSolver()

    for i in range(n):
        for j in range(n):
            x[i][j] = model.new_bool_var(f"x[{i}, {j}]")

    obj = model.new_int_var("obj")
    model.minimize()

    def _get_sub_tour():
        pass
