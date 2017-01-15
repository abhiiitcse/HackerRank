a = [[raw_input(),float(raw_input())] for _ in range(int(raw_input()))]
s = sorted(set([x[1] for x in a]))
for name in sorted(x[0] for x in a if x[1] == s[1]):
    print name

