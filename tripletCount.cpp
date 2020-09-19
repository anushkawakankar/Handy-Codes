#include<iostream>
#include<bits/stdc++.h>
int countTheTriplets(int *a,int n)
{
    sort(a,a+n);
    //1 2 3 5
    int j,k,c=0;
    for(int i=0;i<n-2;i++)
    {
        j=i+1;
        k=j+1;
        while(k<n)
        {
            if(a[i]+a[j]==a[k])
            {
                c++;
                j++;
                //k--;
            }
            else if(a[i]+a[j]<a[k])
            {
                j++;
                k--;
            }
            k++;
        }
    }
    if(c==0)
    {
        return -1;
    }
    else
    {
        return c;
    }
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
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cout<<countTheTriplets(a,n)<<endl;
	}
	return 0;
}
