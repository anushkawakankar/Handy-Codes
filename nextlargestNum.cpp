#include <iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    ll a[n];
	    for(ll i = 0;i<n;i++)
	        cin>>a[i];
	   stack<ll> s;
	   for(ll i=0;i<n;i++)
	   {
	       if(s.empty()) s.push(a[i]);
	       else if(a[i] >= s.top())
	       {
					 // cout<<"enterin for "<<a[i]<<" and "<<s.top()<<endl;
	           while(!s.empty())
	           {
	               cout<<a[i]<<" ";
	               s.pop();
	           }
						 s.push(a[i]);
	       }
	       else s.push(a[i]);
	   }
	   while(!s.empty())
	   {
	       s.pop();
	       cout<<"-1 ";
	   }
	   cout<<endl;
	}
	return 0;
}
