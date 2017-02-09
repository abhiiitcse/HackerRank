import re
n = input()
for i in range(n):
    print bool(re.search(r'^[+-]?[\d]*\.[\d]+$',raw_input()))
    
