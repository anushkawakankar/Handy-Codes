from collections import Counter

def maxCount(a):
    if(len(a) == 0):
        return 0
    freq = Counter(a)
    res = -1
    for key,val in freq.items():
        if(key == val):
            res = max(res, key)
    return res

# n = int(input())
a = []
inp = input()
inp = inp.split(' ')
for i in inp:
    a.append(int(i))

print(maxCount(a))
