s = input()
n = input()
n = int(n)

count = s.count('a')

len = len(s)
occ = int(n/len)
count = count*occ
# print(count)
# print(occ)
fullocc = occ*len
left = n - fullocc

count2 = s.count('a',0,left)
# print(count2)
print(count+count2)
