if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())
    x = max(arr)
    y = []
    for i in range(len(arr)):
        if arr[i]!=x:
            y.append(arr[i])
    print max(y)
    

