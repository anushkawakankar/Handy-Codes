#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string RmvDpl(string str)
{
    string res="";

    int i=0;
    while(i<str.size())
    {
        bool not_rpt=0;
        if(i<str.size()-1&&str[i]==str[i+1])
         {
             while(str[i]==str[i+1])
              i++;
             not_rpt=1;
         }

        if(not_rpt==0)
         res+=str[i];

        i++;
    }

    if(str.size()==res.size())
     return res;

    return RmvDpl(res);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string str;
        cin>>str;

        cout<<RmvDpl(str)<<endl;

    }


  return 0;

}
