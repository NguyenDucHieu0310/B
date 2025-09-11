import random

def input_data():
    d = {}
    eq = {}
    neq = {}
    leq = {}

    line = input().split()
    while(line[0] != '#'):
        if line[0] == 'Var':
            var_name, a, b = line[1:]
            a, b = map(int, [a, b])
            d[var_name] = [a, b]
            eq[var_name] = []
            neq[var_name] = []
            leq[var_name] = []

        if line[0] == 'Eq':
            a, X, b, Y, c = line[1:]

            a, b, c = map(int, [a, b, c])

            eq[X].append([a, X, b, Y, c])
            eq[Y].append([-b, Y, -a, X, c])

        if line[0] == 'Neq':
            a, X, b, Y, c = line[1:]

            a, b, c = map(int, [a, b, c])

            neq[X].append([a, X, b, Y, c])
            neq[Y].append([-b, Y, -a, X, c])

        if line[0] == 'Leq':
            a, X, b, Y, c = line[1:]

            a, b, c = map(int, [a, b, c])

            leq[X].append([a, X, b, Y, c])
            leq[Y].append([-b, Y, -a, X, c])

        line = input().split()

    return d, eq, neq, leq

def main():
    d, eq, neq, leq = input_data()
    x_name = [key for key in d.keys()]
    random.shuffle(x_name)
    x = {key:d[key][0] for key in x_name}

    def _check(i):
        var_name = x_name[i]
        for a, X, b, Y, c in eq[var_name]:
            if Y in x_name[:i]:
                if not a*x[X] == b*x[Y] + c:
                    return False
                
        for a, X, b, Y, c in neq[var_name]:
            if Y in x_name[:i]:
                if not a*x[X] != b*x[Y] + c:
                    return False
                
        for a, X, b, Y, c in leq[var_name]:
            if Y in x_name[:i]:
                if not a*x[X] <= b*x[Y] + c:
                    return False
                
        return True
    
    flag = False
    def _back_track(i):
        flag = False
        var_name = x_name[i]
        for v in range(d[var_name][0], d[var_name][1]+1):
            x[var_name] = v
            if not _check(i):
                continue

            if i == len(x_name) - 1:
                print(len(x_name))
                for key in x_name:
                    print(key, x[key])
                return True
            
            else:
                flag = _back_track(i+1)

            if flag:
                return True

        return False

    if not _back_track(0):
        print("-1")


if __name__ == '__main__':
    main()