from collections import deque
n = input()
for i in range(n):
    possible = True
    foundtillnow = 2147483649
    dqlen = input()
    val = deque(map(int,raw_input().strip().split()))
    assert(len(val)==dqlen)
    while(len(val) > 0):
        left = val[0]
        right = val[-1]
        max_in_both = 0
        if right>left:
            max_in_both = -1
        if val[max_in_both] > foundtillnow:
            possible = False
            break
        else:
            foundtillnow = val[max_in_both]
            if max_in_both == 0:
                val.popleft()
            else:
                val.pop()
    if possible:
        print "Yes"
    else:
        print "No"
        
        
