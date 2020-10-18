// given arr and dep times of n trains, how many platforms reqd minimum

#include <iostream>
using namespace std;
#include<stdlib.h>
#include<bits/stdc++.h>

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n], d[n];
	    for(int i = 0;i<n;i++)
	        cin>>a[i];
	   for(int i = 0;i<n;i++)
	        cin>>d[i];

	   sort(a,a+n);
	   sort(d,d+n);
	   int pf = 1,c,j;
	   for(int i = 1;i<n;i++)
	   {
	       while(j<i)
	       {
	           if(a[j]<=a[i] && a[i]<=d[j])
	                c++;
	           j++;
	       }
	       if(pf<c) pf=c;
	   }
	   cout<<pf<<endl;
	}
}
