n,x = map(int,raw_input().strip().split())
val = list()
for i in range(x):
    val.append(map(float,raw_input().strip().split()))
zipped_val = zip(*val)
for i in range(len(zipped_val)):
    print "%.1f"%(sum(zipped_val[i])/float(x))
