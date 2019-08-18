#include <bits/stdc++.h>
using namespace std;

void rotate(int a[],int b[], int n, int d)
{
  int i=0;
  for(i=0;i<n;i++)
  {
    b[i] = a[(i+d)%n];
  }
  return;
}
int main()
{
  int n;
  int d;
  cin>>n;
  cin>>d;
  int a[n],b[n];
  for(int i = 0;i<n;i++)
  {
    cin>>a[i];
    b[i]=0;
  }
  rotate(a,b,n,d);
  for(int i =0;i<n;i++)
  {
    cout<<b[i]<<" ";
  }
  cout<<endl;
}
