import re
val = raw_input().strip()
m = re.search(r'([A-Za-z0-9])\1+',val)
if m:
    print m.group(1)
else:
    print -1
