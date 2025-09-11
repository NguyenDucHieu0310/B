def input_data():
    n = int(input())
    D = [0]*n
    for i in range(n):
        D[i] = list(map(int, input().split()))
    leq = [[] for i in range(n)]
    geq = [[] for i in range(n)]
    eq1 = [[] for i in range(n)]
    eq2 = [[] for i in range(n)]

    ct = input()
    while(ct != '#'):
        ct = ct.split()
        if (ct[0] == 'LEQ'):
            i, j, a = map(int, ct[1:])
            i -= 1
            j -= 1

            leq[i].append([i, j, a])
            geq[j].append([i, j, a])

        else:
            i, j, a, b = map(int, ct[1:])
            i -= 1
            j -= 1

            eq1[i].append([i, j, a, b])
            eq2[j].append([i, j, a, b])

        ct = input()

    return n, D, leq, geq, eq1, eq2

def main():
    n, D, leq, geq, eq1, eq2 = input_data()

    def _prune(k):
        new_d = []
        
        for x in D[k]:
            flag = True

            for i, j, a in leq[k]:
                if not any(x <= x2 + a for x2 in D[j]):
                    flag = False
                    break

            if not flag: 
                continue

            for i, j, a in geq[k]:
                if not any(x1 <= x + a for x1 in D[i]):
                    flag = False
                    break

            if not flag:
                continue

            for i, j, a, b in eq1[k]:
                if not any(x == x2*a + b for x2 in D[j]):
                    flag = False
                    break

            if not flag:
                continue

            for i, j, a, b in eq2[k]:
                if not any(x1 == x*a + b for x1 in D[i]):
                    flag = False
                    break

            if not flag:
                continue

            new_d.append(x)

        if len(new_d) != len(D[k]):
            D[k] = new_d
            return True
        else:
            return False

    
    update = True
    while(update):
        update = False
        for k in range(n):
            update = update or _prune(k)

    lines = [0]*n
    is_feasible = True
    for k in range(n):
        D[k].sort()
        if len(D[k]) > 0:
            lines[k] = f"{len(D[k])} " + " ".join([str(element) for element in D[k]])
        else:
            is_feasible = False
            break

    if is_feasible:
        for k in range(n):
            print(lines[k])
    else:
        print('FAIL')

if __name__ == '__main__':
    main()
