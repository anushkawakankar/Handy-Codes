//max from each subarray of k elements

#include<bits/stdc++.h>
#define forall(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k;
	    cin>>n>>k;
	    int a[n];
	    forall(i,0,n) cin>>a[i];
	    forall(i,0,n-k+1)
	        cout<<*max_element(a+i, a+i+k)<<' ';
	    cout<<'\n';
	}
}
