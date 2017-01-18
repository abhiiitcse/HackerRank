import calendar
inp = map(int,raw_input().strip().split())
val = calendar.weekday(inp[2],inp[0],inp[1])
print calendar.day_name[val].upper()
