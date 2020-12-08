t = int(input())
for _ in range(t):
    m,n = input().split(' ')
    m = int(m)
    n = int(n)

    arr1 = []
    for i in range(m):

        row = input().split(' ')
        arr1.append(row)

    arr2 = []
    for i in range(m):
        row = input().split(' ')
        arr2.append(row)

    print(arr1)
    print(arr2)
    # t = t-1
    count_region = 0
    for i in range(m):
        for j in range(n):
            if(arr1[i][j] == 1 and arr2[i][j] == 1):
                if(i == 0 and j == 0):
                    count += 1
                elif(j<1 and arr1[i-1][j] == 1 and arr2[i-1][j] == 1):
                    continue
                elif(i<1 and arr1[i][j-1] == 1 and arr2[i][j-1] == 1):
                    continue
                else:
                    count+=1
    print(count)
