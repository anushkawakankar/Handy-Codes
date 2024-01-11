# Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

# Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

# For example, swapping at indices 0 and 2 in "abcd" results in "cbad".


class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        diffs = [i for i in range(len(s)) if s[i] != goal[i]]
        if s==goal and len(set(s))<len(s):
            return True        
        if len(diffs)==2:
            i, j = diffs
            s_list = list(s)
            s_list[i], s_list[j] = s_list[j], s_list[i]
            swapped_s = ''.join(s_list)
            return swapped_s==goal


            

        





            
