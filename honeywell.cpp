#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int calculateLoc(int t, int n , int areas[])
{
  if(t==n)
    return 0;
  else if(t>n)
    return -1;
  int diffNearestLoc[n];
  diffNearestLoc[0] = areas[1]-areas[0];
  diffNearestLoc[n-1] = areas[n-1]-areas[n-2];
  int i;
  for(i=1;i<n-1;i++)
  {
    diffNearestLoc[i]= (areas[i+1]-areas[i])>(areas[i]-areas[i-1])?(areas[i]-areas[i-1]):(areas[i+1]-areas[i]);
  }
  for(i=0;i<n;i++)
  {
    cout<<diffNearestLoc[i]<<" ";
  }
  cout<<endl;
  return 0;
}
int main()
{
  int t;
  cin>>t;
  int n;
  cin>>n;
  int i;
  int areas[n];
  for(i=0;i<n;i++)
  {
     cin>>areas[i];
  }
  int diff = calculateLoc(t,n,areas);
  cout<<diff<<endl;
}
