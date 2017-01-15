from collections import Counter
X = input()
shoes_size = map(int,raw_input().strip().split())
N = input()
total_earn = 0
mappings = Counter(shoes_size)
for i in range(N):
    (ss,xi) = map(int,raw_input().strip().split())
    if mappings[ss]>0:
        mappings[ss] -= 1
        total_earn += xi;

print total_earn
