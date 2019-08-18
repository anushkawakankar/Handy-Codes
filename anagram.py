q=input()
q = int(q)
for i in range(q):
    s = input()
    n = len(s)
    mp = dict()

    for j in range(n):
        sb = ''
        for k in range(j,n):
            sb = ''.join(sorted(sb + s[k]))
            mp[sb] = mp.get(sb,0)
            mp[sb]+=1

    anas = 0
    for k,v in mp.items():
        anas+= (v*(v-1))//2

    print(anas)
