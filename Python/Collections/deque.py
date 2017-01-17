from collections import deque
dq = deque()
n = input()
for i in range(n):
    inp = raw_input().strip().split()
    if inp[0] == 'append':
        dq.append(int(inp[1]))
    if inp[0] == 'pop':
        dq.pop()
    if inp[0] == 'appendleft':
        dq.appendleft(int(inp[1]))
    if inp[0] == 'popleft':
        dq.popleft()

for i in dq:
    print i,
print
