#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i)
{
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if(l<n && a[largest] < a[l])
    largest = l;
  if(r<n && a[largest] < a[r])
    largest = r;

  if(largest != i)
  {
    swap(a[largest], a[i]);
    heapify(a,i,0);
  }
}

void heapsort(int a[], int n)
{
  int i;
  for(i=n/2-1; i>=0;i--)
  {
    heapify(a,n,i);
  }
  for(i=n-1;i>=0;i--)
  {
    swap(a[0],a[i]);
    heapify(a,i,0);
  }
}

int main()
{
  int  n;
  cin>>n;
  int i;
  int a[n];
  for(i=0;i<n;i++)
    cin>>a[i];
  heapsort(a,n);
  for(i=0;i<n;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}
