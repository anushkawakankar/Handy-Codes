#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node{
  int val;
  struct Node* next;
}node;

void addToList(struct Node* head,, int val)
{
  struct Node* temp = head;
  while(temp != NULL)
  {
      temp = temp->next;
  }
  temp 
}

int main()
{
  struct Node* head = NULL;
  int c;
  cin>>c;
  if(c==1)
  {
    int a;
    cin>>a;
    while(a>=0)
    {
      addToList(head,a);
      cin>>a;
    }
  }
  if(c==2)
  {
    printList(head);
  }
}
