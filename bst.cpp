#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
struct node
{
  int key;
  struct node* left;
  struct node* right;
};

void search(struct node* node, int val)
{
  if(node == NULL)
    printf("Not found\n");
  if(node->key == val)
    printf("Found\n");
  if(node->key > val)
    search(node->left, val);
  else if(node->key < val)
    search(node->right,val);
}

void inorder(struct node* node)
{
  if(node != NULL)
  {
    inorder(node->left);
    printf("%d ",node->key);
    inorder(node->right);
  }

}

struct node* newNode(int val)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->key = val;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}
//
struct node* insert(struct node* node, int val)
{
  if (node == NULL)
    return newNode(val);

  if(val < node->key)
    node->left =  insert(node->left, val);
  else if(val > node->key)
    node->right = insert(node->right, val);

  return node;
}


int main()
{
  printf("enter n\n");
  int n;
  scanf("%d",&n);
  int temp;
  int i;
  struct node* root = NULL;
  scanf("%d",&temp);
  root = insert(root,temp);
  for(i=1;i<n;i++)
  {
    scanf("%d",&temp);
    insert(root,temp);
  }
  printf("done\n");
  inorder(root);
  int lol;
  printf("\nEnter num to search\n");
  scanf("%d",&lol);
  search(root,lol);

}
