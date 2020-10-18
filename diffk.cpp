// given array retturn 1 if two elements exist w diff k

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int freq[100005];

int diffkFunc(int a[], int n,int k)
{
  int i;
  for(i=0;i<n;i++)
  {
    freq[a[i]]++;
    if(k == 0 && freq[a[i]]>=2)
      return 1;
    else if(k!=0)
    {
      if(freq[a[i]+k] > 0 || freq[a[i]-k] > 0)
        return 1;
    }
  }
  return 0;
}

int main()
{
  int n;
  cin>>n;
  int a[n];
  int i;
  for(i=0;i<n;i++)
    cin>>a[i];
  int k;
  cin>>k;
  int ans = diffkFunc(a,n,k);
  cout<<ans<<endl;
}
