#include <iostream>
using namespace std;
#include <string>
#include <bits/stdc++.h>

void permute(string s, int l, int r,int n)
{
    if(l==r && s.length()==n) cout<<s<<" ";
    else
    {
        for(int i = l; i<= r; i++)
        {
            swap(s[l],s[i]);
            permute(s,l+1,r,n);
            swap(s[l],s[i]);
        }
    }

}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	   // cout<<s<<" "<<s.length()<<endl;
	    permute(s,0,s.length()-1,s.length());
	   cout<<endl;
	}
	return 0;
}
