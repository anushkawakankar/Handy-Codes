# You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

# Return the merged string.

class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        len1=len(word1)
        len2=len(word2)
        joinstr=''
        joinstr1=''
        finstr=''
        if len1==len2:
            for i,j in zip(word1,word2):
                joinstr+=i+j
            return joinstr
        else:
            diff=max(len1,len2)-min(len1,len2)
            adjstr1=word1 if len1<len2 else word2
            adjstr2=word2 if len2>len1 else word1
            adjstr1=adjstr1 + " "*diff
            finstr=zip(adjstr2,adjstr1)
            # print(list(finstr))
            for i,j in finstr:
                # print(i,j)
                if len1>len2:
                    joinstr1+=i+j
                    joinstr1=joinstr1.replace(" ","")
                elif len1<len2:
                    joinstr1+=j+i
                    joinstr1=joinstr1.replace(" ","")
            return joinstr1
