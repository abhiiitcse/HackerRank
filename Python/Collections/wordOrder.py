from collections import OrderedDict
n = input()
odict = OrderedDict()
for i in range(n):
    word = raw_input().strip()
    if word in odict:
        odict[word] += 1
    else:
        odict[word] = 1

print len(odict)
for k,v in odict.items():
    print v,
print
