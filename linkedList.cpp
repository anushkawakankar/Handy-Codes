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
}
