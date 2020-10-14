#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
struct node
{
  int key;
  struct node* left;
  struct node* right;
};

void inorder(struct node* root)
{
  if(root != NULL)
  {
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
  }
}

void search(struct node* root, int key)
{
  if(root == NULL)
  {
    printf("NOT FOUND\n");
    return;
  }
  if(root->key == key)
    printf("FOUND\n");
  if(root->key>key)
    search(root->left,key);
  else if(root->key<key)
    search(root->right,key);
}
struct node* newNode(int key)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}
struct node* insert(struct node* node, int key)
{
  if(node == NULL)
    return newNode(key);
  if(key<node->key)
    node->left = insert(node->left,key);
  else if(node->key<key)
    node->right = insert(node->right,key);
  return node;
}
int main()
{
  int n;
  scanf("%d",&n);
  int temp,i;
  struct node* root = NULL;
  scanf("%d",&temp);
  root = insert(root,temp);
  for(i=0;i<n-1;i++)
  {
    scanf("%d",&temp);
    insert(root,temp);
  }
  inorder(root);
  printf("\nEnter num to search\n");
  scanf("%d",&temp);
  search(root,temp);

}
