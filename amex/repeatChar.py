from collections import Counter

def sol(s):
    freq = Counter(s)
    # print(freq)
    final = ''
    for key,val in freq.items():
        if(val == 2 and key != " "):
            final = key
    print(final)


str = input()
sol(str)
