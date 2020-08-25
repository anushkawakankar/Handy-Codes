#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;


int sqrtfind(int n)
{
  if(n == 0 || n == 1) return n;

  int start = 1, end = n, ans;

  while(start <= end)
  {
    int mid = (start+end)/2;
    if(mid*mid == n)
      return mid;
    else if( mid*mid < n)
    {
      start = mid+1;
      ans = mid;
    }
    else
      end = mid-1;

  }
  return ans;
}

int main()
{
  float n;
  cin>>n;
  cout<<sqrtfind(n);
}
