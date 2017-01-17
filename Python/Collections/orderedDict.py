from collections import OrderedDict
n = input()
odict = OrderedDict()
for i in range(n):
    inp = raw_input().strip().split()
    key_val = ''
    value_val = int(inp[-1])
    for i in range(len(inp)-1):
        key_val += inp[i]
        key_val += ' '
    if key_val.strip() in odict.keys():
        odict[key_val.strip()] += value_val
    else:
        odict[key_val.strip()] = value_val
for k,v in odict.items():
    print k,v
