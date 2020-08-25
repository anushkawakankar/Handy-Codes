// Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
// return 1->4->3->2->5->NULL.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* a, int m, int n) {
  m--;
  n--;
  int f=0;
  if(m==n || n<m)
    return a;
  ListNode* head=a;
  ListNode* head2=a;
  ListNode* prev1=head;
  ListNode* temp=NULL;
  ListNode* nxt=NULL;
  ListNode* prev=a;
  ListNode* aft=NULL;
  while(m){
    m--;
    prev1=head;
    head=head->next;
    f = 1;
  }
  while(n){
    n--;
    head2=head2->next;
    aft=head2->next;
  }
  prev=head;
  head=head->next;
  prev->next=aft;
  temp=head;
  while(temp!=aft){
    nxt=temp->next;
    // cout<<"nxt is "<val<<endl;
    temp->next=prev;
    prev=temp;
    // cout<<"prv is "<val<<endl;
    temp=nxt;
  }
  if(f==1)
  {
    prev1->next=prev;
    return a;
  }
  else
    return prev;
}
