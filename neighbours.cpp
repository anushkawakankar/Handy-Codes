#include <bits/stdc++.h>
using namespace std;
int arr[20000],inc[20000],n;

int FindMaxSum(int arr[], int n) 
{ 
  int incl = arr[0]; 
  int excl = 0; 
  int excl_new; 
  int i; 
  int p ;
  
  for (i = 1; i < n; i++) 
  { 
     excl_new = (incl > excl)? incl: excl;
     if (incl > excl)
      {
        excl_new = incl;
        inc[i-1] = 1;
      } 
      else
      {
        excl_new = excl;
        inc[i-1] = 0;
      }
  
     incl = excl + arr[i]; 
     excl = excl_new; 
  } 
  
    if (incl>excl)
    {
      printf("%d",arr[n-1]);
      p = 1;
    }
    else
    {
      p = 0;
    }
    for (int i = n-2; i >= 0; i--)
    {
      if (p == 1)
      {
        p = 0 ;
      }
      else
      {
        if (inc[i])
        {
          printf("%d",arr[i]);
          p = 1;
        }
        else
        {
          p = 0;
        }
      }
    }
    return ((incl > excl)? incl : excl); 
} 
  
int main() 
{ 
  int t;
  cin>>t;
  for (int j = 0; j < t; ++j)
  {
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
      cin>>arr[i];
    }
    FindMaxSum(arr, n);
    printf("\n");

  }
  return 0; 
} 