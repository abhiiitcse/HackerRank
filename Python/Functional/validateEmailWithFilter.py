import re
lst = list()
n = input()
for i in range(n):
    lst.append(raw_input().strip())
print sorted(list(filter(lambda x: re.search(r'^[\w\d-]+@[A-Za-z0-9]+\.\w?\w?\w$',x),lst)))
