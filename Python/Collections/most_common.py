from collections import Counter
from operator import itemgetter
inp = raw_input().strip()
val = sorted(sorted(Counter(inp).items()),key=itemgetter(1),reverse=True)[:3]
for i,t in val:
    print i,t
