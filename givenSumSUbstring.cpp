#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

void findInd(int a[],int n,int sum)
{
  long long curr = a[0],i = 0,j=0;
  for(j=1;j<n;j++)
  {
    curr = curr + a[j];
    if(curr == sum)
    {
      cout<<i+1<<" "<<j+1<<endl;
      return;
    }
    while(curr > sum)
    {
      curr -= a[i];
      i++;
      if(curr == sum)
      {
        cout<<i+1<<" "<<j+1<<endl;
        return;
      }
    }
  }
  cout<<"-1"<<endl;
  return;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long n,s;
    cin>>n>>s;
    long long a[n];
    long long i;
     for(i=0;i<n;i++)
     {
       cin>>a[i];
     }
     findInd(a,n,s);
  }
}
