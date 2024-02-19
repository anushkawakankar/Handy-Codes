# Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

# Return the decimal value of the number in the linked list.

# The most significant bit is at the head of the linked list.

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        # binary=''
        # curr=head
        # while curr:
        #     binary+=str(curr.val)
        #     curr=curr.next
        # return int(binary,2)
        if not head:
            return None
        curr=head
        result=curr.val
        while curr.next:
            result = result *2 + curr.next.val
            curr=curr.next
        return result
