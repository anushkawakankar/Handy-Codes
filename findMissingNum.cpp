#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
	return 0;
}

int findEl(int a[], int l,int h)
{
  // cout<<"checking between "<<l<<" "<<h<<endl;
  int m = (l+h)/2;
  if(a[l] == l && a[l+1] != l+1 ) return l+1;
  if(a[h] != h && a[h-1] == h-1 ) return h;
  if(a[m] == m && a[m+1] != m+1 ) return m+1;
  if(a[m] != m && a[m-1] == m-1 ) return m;

  if(a[m] == m)
  {
    return findEl(a,m+1,h);
  }
  else
    return findEl(a,l,m);
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int a[n];
    a[0] = 0;
    for(int i = 1;i<n;i++)
    {
      cin>>a[i];
    }
    qsort(a,n,sizeof(int),compare);
    cout<<findEl(a,0,n)<<endl;
  }
}
