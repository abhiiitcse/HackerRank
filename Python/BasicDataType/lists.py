if __name__ == '__main__':
    N = int(raw_input())
    result = []
    for i in range(N):
        val = raw_input().split()
        if len(val)>0:
            if val[0] == 'print':
                print result
            elif val[0] == 'append':
                result.append(int(val[1]))
            elif val[0] == 'pop':
                result.pop()
            elif val[0] == 'insert':
                result.insert(int(val[1]),int(val[2]))
            elif val[0] == 'remove':
                result.remove(int(val[1]))
            elif val[0] == 'sort':
                result.sort()
            elif val[0] == 'reverse':
                result.reverse()
                

