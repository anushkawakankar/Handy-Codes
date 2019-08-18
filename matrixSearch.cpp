#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int search(int r,int c,int e)
{
  int smallest = a[0][0];
  int largest = a[r-1][c-1];
  if(e<smallest || e>largest)
  {
    cout<<"not found"<<endl;
    return 0;
  }
  int curr = a[0][c-1];
  if(curr == e)
  {
    cout<<"Found"<<endl;
    return 1;
  }
  int i = 0, j = c-1;
  while(i<r && j>=0)
  {
    curr = a[i][j];
    if(e>curr)
      i++;
    else if(e<curr)
      j--;
    else if(e == curr)
    {
      cout<<"Found"<<endl;
      return 1;
    }
  }
  cout<<"Not found\n";
  return 0;

}
int main()
{
  int r,c;
  cin>>r>>c;
  int i,j;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cin>>a[i][j];
    }
  }
  int e;
  cin>>e;
  search(r,c,e);
}
