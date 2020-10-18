// longets palindrome substring

#include<iostream>
using namespace std;
string longestPalindrome(string s)
{
    string str="",rstr="",lps="";
    int p=0,q=0;
    for(int i=0;i<s.length();i++)
    {
        str=str+s[i];
        rstr=s[i]+rstr;
        if(str==rstr)
        {
            if(lps.length()<str.length())
            {
                lps=str;
            }
        }
        else
        {
            if(p!=0&&s[p-1]==s[i])
            {
                str=s[p-1]+str;
                rstr=rstr+s[p-1];
                if(lps.length()<str.length())
                {
                    lps=str;
                }
                p--;
            }
            else
            {
                i=++q;
                str.clear();
                rstr.clear();
                str=str+s[i];
                rstr=s[i]+rstr;
                p=i;
            }
        }
    }
    return lps;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<longestPalindrome(s)<<endl;
	}
	return 0;
}
