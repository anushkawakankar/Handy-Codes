//max value of h for an array such that there's at least h elements with value more than h
class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)
        print(citations)
        h = 0
        while(h<len(citations)):
            if(citations[h] > h):
                h = h+1
            else:
                break
        return h
