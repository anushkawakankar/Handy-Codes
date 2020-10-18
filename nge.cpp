//next greatest element

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
void findnge(int a[], int n)
{
  stack <int> s;
  s.push(a[0]);
  for(int i = 1;i<n;i++)
  {
    if(s.empty())
      s.push(a[i]);

    while(!s.empty() && a[i]>s.top())
    {
      printf("%d -> %d\n",s.top(),a[i]);
      s.pop();
    }
    s.push(a[i]);
  }
  while(!s.empty())
  {
    printf("%d -> -1\n",s.top());
    s.pop();
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  int i;
  int a[n];
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  findnge(a,n);
}
