from collections import namedtuple
ts = input()
IDEN = namedtuple('IDEN',','.join(raw_input().strip().split()))
total_marks = 0.0
for i in range(ts):
    val = IDEN(*(raw_input().strip().split()))
    total_marks += float(val.MARKS)
print total_marks/ts
