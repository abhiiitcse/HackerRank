if __name__ == '__main__':
    x = int(raw_input())+1
    y = int(raw_input())+1
    z = int(raw_input())+1
    n = int(raw_input())
    final_list=[[i,j,k] for i in xrange(x) for j in xrange(y) for k in xrange(z) if sum([i,j,k])!=n]
    print final_list
                    

