from collections import defaultdict
d = defaultdict(list)
(n,m) = map(int,raw_input().strip().split())
for i in range(n):
    val = raw_input().strip()
    d[val].append(i+1)

for j in range(m):
    val = raw_input().strip()
    if val in d:
        print ' '.join(map(str,d[val]))
    else:
        print "-1"
