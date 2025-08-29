stack = []
for char in input():
    if char in "{[(":
        stack.append(char)
    elif stack and (char == '}' and stack[-1] == '{' or char == ']' and stack[-1] == '[' or char == ')' and stack[-1] == '('):
        stack.pop()
    else:
        print(0)
        exit()
print(1 if not stack else 0)
