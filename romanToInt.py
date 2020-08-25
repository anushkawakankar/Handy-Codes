class Solution:
    # @param A : string
    # @return an integer
    def romanToInt(self, A):
        dic = {
        'I':1,
        'IV':4,
        'V':5,
        'VI':6,
        'VII':7,
        'VIII':8,
        'IX':9,
        'X':10,
        'L':50,
        'C':100,
        'D':500,
        'M':1000

        }
    # below ref variable will be our exit criteria
        ref = ['I','IV','V','VI','VII','VIII','IX','X']
        # our answer will be stored in below variable
        num = 0
        prev = 0
        for i in range(0,len(A)):
            # if last part matches directly add and return
            if A[i:] in ref:
                return num+dic[A[i:]]
            else:
                # if next is less than previous add the value
                if dic[A[i]]<=dic[A[prev]]:
                    num+=dic[A[i]]
                else:
                # if current is more than previous, reduce the previous
                # and add the current-previous ,i.e, add current and
                # reduce twice the previous
                    num+=dic[A[i]]-(2*dic[A[prev]])
            prev = i

        return num
