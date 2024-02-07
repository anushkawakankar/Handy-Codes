# Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 * 3 * ... * x and by convention, 0! = 1.

# For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has two zeroes at the end.
# Given an integer k, return the number of non-negative integers x have the property that f(x) = k.


import math
class Solution:
    def preimageSizeFZF(self, k: int) -> int:       
        i = 5*(k+1)
        start = 1
        end = i
        while(start <= end):            
            mid = (start+end)//2
            trailingz = self.trailingzeros(mid)
            if(trailingz > k and self.trailingzeros(mid-1) <k ):
                return 0
            if(trailingz < k and self.trailingzeros(mid+1) > k):
                return 0
            if(trailingz==k):
                break
            elif(trailingz<k):
                start = mid+1 
            else:
                end = mid - 1
                
        return 5
    
    def trailingzeros(self, num):
        if num<=4:
            return 0
        
        count_5=0
        current_power_of_5=5

        while current_power_of_5<=num:
            count_5+=num//current_power_of_5
            current_power_of_5*=5
        
        count_2=num//2

        return min(count_5,count_2)
