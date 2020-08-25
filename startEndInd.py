#print starting and ending index of B in a tuple A. [-1,-1] if not found

import bisect
class Solution:
    # @param A : tuple of integers
    # @param B : integer
    # @return a list of integers
    def searchRange(self, A, B):
        starting = bisect.bisect_left(A, B, 0, len(A)-1)
        ending = bisect.bisect_right(A, B, 0, len(A)-1)
        if(A[ending] != B and A[ending-1] == B):
            ending = ending -1
        if(ending<len(A)-1 and A[ending+1] == B):
            eneding = ending+1
        if(B not in A):
            ending = -1
            starting = -1
        return [starting, ending]
