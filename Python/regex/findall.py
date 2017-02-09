import re
val = raw_input().strip()
m = re.findall(r'[^AEIOUaeiou][AEIOUaeiou]+[^AEIOUaeiou]',val)
if m:
    for mm in m:
        if len(mm)>3:
            print mm[1:-1]
else:
    print -1
