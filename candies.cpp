#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int a[n];
  int b[n];
  int i;
  for(i=0;i<n;i++)
  {
    cin>>a[i];
    b[i] = 1;
  }
  int start = 1;
  if(a[0]>a[1])
  {
    b[0] = 2;
    b[1] = 1;
    start = 1;
  }
  else
  {
    b[0]=1;
  }
  for(i=start;i<n;i++)
  {
    if(a[i]>a[i-1])
      b[i] = b[i-1]+1;
    else if(a[i-1]>a[i] && b[i-1]>1)
      b[i] = 1;
    else if(a[i-1]>a[i] && b[i-1]==1)
    {
      int j=i;
      b[i]=1;
      b[i-1] = 2;
      for(j=i-2;j>=0;j--)
      {
        if(a[j-1]<a[j])
          break;
        else
          b[j]++;
      }
    }
  }
  int sum = 0;
  for(i=0;i<n;i++)
  {
    // cout<<b[i]<<" ";
    sum += b[i];
  }
  // cout<<endl;
  cout<<sum<<endl;
}
