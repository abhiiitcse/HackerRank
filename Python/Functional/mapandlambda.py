cube = lambda x: x**3
def fibonacci(n):
    ret_list = list()
    if n>0:
        ret_list.append(0)
    if n>1:
        ret_list.append(1)
    if n >= 3:
        a = 0
        b = 1
        for i in range(2,n):
            ret_list.append(a+b)
            temp = a + b
            a = b
            b = temp
    return ret_list
if __name__=='__main__':
    n = input()
    print map(cube,fibonacci(n))
