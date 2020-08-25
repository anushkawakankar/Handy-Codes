from fractions import gcd

n, k = map(int,raw_input().split())
a = map(int,raw_input().split())
v = []
for i in range(1, 2**n):
    x = i
    l = 1
    c = -1
    for j in range(n):
        if x%2:
            c = -c
            l = (l/gcd(l,a[j])) * a[j]
        x /= 2
    v.append([l,c])

def calc(n):
    a = 0
    for x in v:
        if x[1] == 1:
            a += n/x[0]
        else:
            a -= n/x[0]
    return a

l = 1
r = 10**32
while l < r:
    m = (l+r)/2
    if calc(m) >= k:
        r = m
    else:
        l = m+1
print (l+r)/2
