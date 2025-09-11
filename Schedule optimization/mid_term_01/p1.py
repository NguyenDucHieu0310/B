n = int(input())
v = list(map(int, input().split()))

all_violations = 0
ct_is_equal = {}
ct_is_le = {}
ct_is_ge = {}
count = {}

for i in range(n):
    if v[i] in count:
        count[v[i]] += 1
    else:
        count[v[i]] = 1

def is_equal(i, j):
    if i not in ct_is_equal:
        ct_is_equal[i] = list()
        ct_is_equal[i].append(j)
    else:
        ct_is_equal[i].append(j)

    if j not in ct_is_equal:
        ct_is_equal[j] = list()
        ct_is_equal[j].append(i)
    else:
        ct_is_equal[j].append(i)

    return abs(v[i] - v[j])

def is_equal2(i, j):
    return abs(v[i] - v[j])



def is_le(i, j):
    if i not in ct_is_le:
        ct_is_le[i] = list()
        ct_is_le[i].append(j)
    else:
        ct_is_le[i].append(j)

    if j not in ct_is_ge:
        ct_is_ge[j] = list()
        ct_is_ge[j].append(i)
    else:
        ct_is_ge[j].append(i)

    return max(0, v[i] - v[j])

def is_le2(i, j):
    return max(0, v[i] - v[j])

def update(i, j):
    global all_violations, ct_is_equal, ct_is_le, ct_is_ge
    ## dif
    if j in count:
        count[j] += 1
    else:
        count[j] = 1
    all_violations += (count[j] - 1) - (count[v[i]] - 1)
    count[v[i]] -= 1
    # print("debug1: ", all_violations)
    ## is_eq
    if i in ct_is_equal.keys():
        for k in ct_is_equal[i]:
            all_violations -= is_equal2(i, k)

    ## is_le
    if i in ct_is_le.keys():
        for k in ct_is_le[i]:
            all_violations -= is_le2(i, k)
    # print("debug2: ", all_violations)

    ## is_ge
    if i in ct_is_ge.keys():
        for k in ct_is_ge[i]:
            all_violations -= is_le2(k, i)
    # print("debug3: ", all_violations)

    v[i] = j

    ## is_eq
    if i in ct_is_equal.keys():
        for k in ct_is_equal[i]:
            all_violations += is_equal2(i, k)
    # print("debug4: ", all_violations)

    ## is_le
    if i in ct_is_le.keys():
        for k in ct_is_le[i]:
            all_violations += is_le2(i, k)
    # print("debug5: ", all_violations)

    ## is_le
    if i in ct_is_ge.keys():
        for k in ct_is_ge[i]:
            all_violations += is_le2(k, i)
    # print("debug6: ", all_violations)


cmd = input().split()
while(cmd[0] != "#"):
    ## check the command
    if (cmd[0] == "violations"):
        print(all_violations)

    elif (cmd[0] == "update"):
        i = int(cmd[1]) - 1
        j = int(cmd[2])

        if v[i] != j:
            update(i, j)   
        
        # print("----------")

    elif (cmd[1] == "AllDifferent"):
        all_violations += sum(i*(i-1)//2 for i in count.values())

    elif (cmd[1] == "IsEqual"):
        i = int(cmd[2]) - 1
        j = int(cmd[3]) - 1
        all_violations += is_equal(i, j)

    elif (cmd[1] == "LessThanEqual"):
        i = int(cmd[2]) - 1
        j = int(cmd[3]) - 1
        all_violations += is_le(i, j)

    cmd = input().split()
