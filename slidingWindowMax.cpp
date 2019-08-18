#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <iterator>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  printf("Program to find the minimum of the maximums of all subsets with k values. Input n and k\n");
  int n,k;
  scanf("%d %d",&n,&k);
  int a[n];
  int i;
  printf("input n numbers\n");
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  }
  set <int, greater <int> > maxheap;
  for(i=0;i<k;i++)
    maxheap.insert(a[i]);

  set <int, greater <int> > :: iterator itr;
  itr = maxheap.begin();
  int curr_max = *itr;
  int min_of_max = curr_max;
  int removed = -1;
  for(i=k;i<n;i++)
  {
    removed++;
    maxheap.erase(a[removed]);
    maxheap.insert(a[i]);
    itr = maxheap.begin();
    curr_max = *itr;

    if(min_of_max > curr_max)
      min_of_max = curr_max;
  }

  cout<<min_of_max<<endl;


}
