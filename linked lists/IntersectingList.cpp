// Write a program to find the node at which the intersection of two singly linked lists begins.
//
// For example, the following two linked lists:
//
//
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗
// B:     b1 → b2 → b3
//
// begin to intersect at node c1.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {

      int c1=0, c2=0;

  ListNode* svar = A;

  while( svar != NULL ){

      ++c1;
      svar = svar->next;
  }

  svar = B;

  while( svar != NULL ){

      ++c2;
      svar = svar->next;
  }

  ListNode* s1 = A;
  ListNode* s2 = B;

  if( c1>c2 ){

      c1 = c1-c2;

      while( c1>0 ){

          s1 = s1->next;
          --c1;
      }
  }
  else{

      c2 = c2-c1;

      while( c2>0 ){

          s2 = s2->next;
          --c2;
      }
  }

  while ( s1 != s2 ){
      s1 = s1->next;
      s2 = s2->next;
    }

  if( s1 != s2 )
      return NULL;

  return s1;


}
