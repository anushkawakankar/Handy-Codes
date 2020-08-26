//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    struct ListNode *p;
    if(A==NULL) return B;
    if(B==NULL) return A;
    if(A->val<B->val) p=A,p->next=mergeTwoLists(A->next,B);
    else p=B,p->next=mergeTwoLists(A,B->next);
    return p;
}
