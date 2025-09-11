# Domain consistency: x1 + x2 <= x3
d1 = list(map(int, input().split()))
d2 = list(map(int, input().split()))
d3 = list(map(int, input().split()))

# Sort the domains for consistency checks
d1.sort()
d2.sort()
d3.sort()

def prun_d1():
    """Prune domain d1 based on the constraint x1 + x2 <= x3."""
    global d1, d2, d3
    updated = False
    new_d1 = []
    for x1 in d1:
        valid = any(x1 + x2 <= x3 for x2 in d2 for x3 in d3)
        if valid:
            new_d1.append(x1)
        else:
            updated = True
    d1 = new_d1
    return updated

def prun_d2():
    """Prune domain d2 based on the constraint x1 + x2 <= x3."""
    global d1, d2, d3
    updated = False
    new_d2 = []
    for x2 in d2:
        valid = any(x1 + x2 <= x3 for x1 in d1 for x3 in d3)
        if valid:
            new_d2.append(x2)
        else:
            updated = True
    d2 = new_d2
    return updated

def prun_d3():
    """Prune domain d3 based on the constraint x1 + x2 <= x3."""
    global d1, d2, d3
    updated = False
    new_d3 = []
    for x3 in d3:
        valid = any(x1 + x2 <= x3 for x1 in d1 for x2 in d2)
        if valid:
            new_d3.append(x3)
        else:
            updated = True
    d3 = new_d3
    return updated

# Iteratively prune the domains until no changes occur
flag = True
while flag:
    flag1 = prun_d1()
    flag2 = prun_d2()
    flag3 = prun_d3()
    flag = flag1 or flag2 or flag3

# Print the resulting domains
line1 = " ".join(map(str, d1))
line2 = " ".join(map(str, d2))
line3 = " ".join(map(str, d3))
print(line1)
print(line2)
print(line3)
