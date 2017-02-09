import re
val = raw_input().strip()
output = re.split(r"[,.]",val)
for i in output:
    if i.isdigit():
        print i
