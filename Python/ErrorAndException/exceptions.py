t = input()
for i in range(t):
    a,b = raw_input().strip().split()
    try:
        val = int(a)/int(b)
        print val
    except ZeroDivisionError as e:
        print "Error Code:",e
    except ValueError as e:
        print "Error Code:",e
