#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int key;
  Node* next;
};

void addToList(Node** head, int val)
{
      Node* new_node = new Node();

      Node *last = *head;

      new_node->key = val;
      new_node->next = NULL;
      if (*head == NULL)
      {
          *head = new_node;
          return;
      }

      while (last->next != NULL)
          last = last->next;

      last->next = new_node;
      return;
}

void insertAfter(Node** head, int val, int after)
{
  Node* new_node = new Node();
  Node* last = *head;
  new_node->key = val;
  while(last->key != after)
        last = last->next;
  new_node->next = last->next;
  last->next = new_node;
}

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->key << " ";
        n = n->next;
    }
}

void swapNodes(Node** head, int x, int y)
{
  if(x==y) return;
  Node* currx = *head, *prevx = NULL;

  while(currx != NULL && currx->key != x)
  {
    prevx = currx;
    currx = currx->next;
  }

  Node* curry = *head, *prevy = NULL;
  while(curry != NULL && curry->key != y)
  {
    prevy = curry;
    curry = curry->next;
  }
  if(curry == NULL || currx == NULL) return;
  if (prevx != NULL)
    prevx->next = curry;
  else
      *head = curry;

  if (prevy != NULL)
      prevy->next = currx;
  else
      *head = currx;

  Node* temp = curry->next;
  curry->next = currx->next;
  currx->next = temp;
}

void deleteNode(Node** head, int val){

  Node* last = *head;
  if(last != NULL && last->key == val)
  {
    *head = last->next;
    free(last);
    return;
  }
  Node* prev;
  while(last != NULL && last->key != val)
  {
    prev = last;
    last = last->next;
  }

  if(last == NULL) return;
  prev->next = last->next;
  free(last);
}

Node* reverseLL(Node** head)
{
  Node* current = *head;
  Node* prev = NULL;
  Node* next = NULL;
  while(current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int nthNode(Node** head, int n)
{
  Node* curr = *head;
  n--;
  while(n--)
    curr=curr->next;
  return curr->key;
}

int detectLoop(Node** head)
{
  Node* slow_p = *head;
  Node* fast_p = *head;
  while(slow_p && fast_p && fast_p->next)
  {
    slow_p = slow_p->next;
    fast_p = fast_p->next->next;
    if(slow_p == fast_p)
        return slow_p->key;
  }
  return -1;
}

int main()
{
  int n;
  cout<<"Enter no. of values and values"<<endl;
  cin>>n;
  int first;
  cin>>first;
  Node* head = NULL;
  head = new Node();
  head->key = first;
  head->next = NULL;
  int in;
  for(int i = 1;i<n;i++){
    cin>>in;
    addToList(&head,in);
  }
  printList(head);
  cout<<endl;
  cout<<"Enter number + which node to add after"<<endl;
  cin>>in;
  int after;
  cin>>after;
  insertAfter(&head,in,after);
  printList(head);
  cout<<"\nEnter node to be deleted"<<endl;
  cin>>in;
  deleteNode(&head,in);
  printList(head);
  cout<<"\nReversed:"<<endl;
  head = reverseLL(&head);
  printList(head);
  cout<<"\nEnter nth node\n";
  cin>>in;
  if(in>n || n<0) cout<<"Doesnt exist\n";
  else
  {
    if(in == 1)
      cout<<head->key<<endl;
    else
      cout<<nthNode(&head,in)<<endl;
  }

  cout<<"Enter nodes to swap\n";
  int sw1, sw2;
  cin>>sw1;
  cin>>sw2;
  swapNodes(&head,sw1,sw2);
  printList(head);
  cout<<endl;
  head->next->next->next->next = head->next;
  cout<<"Detect loop"<<endl;
  cout<<"Loop at: "<<detectLoop(&head)<<endl;
}
