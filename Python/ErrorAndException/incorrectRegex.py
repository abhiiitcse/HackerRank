import re
t = input()
for _ in range(t):
    try:
        reg = re.compile(raw_input().strip())
        print True
    except re.error:
        print False
