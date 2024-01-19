# Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

from collections import Counter
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        strlen=len(s)
        char_count=dict(Counter(s))
        odd=0
        print(char_count)
        for i in char_count.values():
            if i%2:
                odd+=1
        print(odd)
        if odd > k or k>strlen:
            return False
        return True
