import numpy as np
t = int(input())

while(t>0):

    s1 = input()
    s2 = input()
    # print(s1,s2)
    hash = np.zeros((26,2))
    for i in range(26):
        hash[i,1] = -1

    l1 = len(s1)
    l2 = len(s2)

    for i in range(len(s1)):
        # print(ord(s1[i])-97)
        hash[ord(s1[i]) - 97,0] = 1
        if(hash[ord(s1[i])-97,1] == -1):
            hash[ord(s1[i])-97,1] = int(i)

    # earliest = ['$',int(l1-1)]
    ear_car = '$'
    ear_num = 100005

    # print(hash)
    for i in range(l2):
        # print(earliest)
        # print(ear_car, ear_num,s2[i],hash[ord(s2[i])-97,1])
        if(hash[ord(s2[i])-97,1] == -1):
            continue
        if(hash[ord(s2[i])-97,0] == 1 and hash[ord(s2[i])-97,1] < ear_num):
            ear_car = s2[i]
            ear_num = hash[ord(s2[i])-97,1]

    print(ear_car)
    t = t-1
