n = input()
s = map(int,raw_input().split())
first_cond = any(map(lambda x: str(x)==str(x)[::-1],s))
second_cond = all(map(lambda x: x>0,s))
if first_cond and second_cond:
    print True
else:
    print False
