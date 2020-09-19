#include <iostream>
using namespace std;

int max(int a, int b)
{
    if(a>b) return a;
    return b;
}

int maxSum(int a[], int n)
{
    int lsum = a[0], gsum = a[0];
    int i;
    for(i=1;i<n;i++)
    {
        lsum = max(a[i],lsum+a[i]);
        gsum = max(gsum, lsum);
    }
    return gsum;

}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i = 0; i<n;i++)
	        cin>>a[i];
	   cout<<maxSum(a,n)<<endl;
	}
	return 0;
}
