#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

string adder(string a, string b)
{
  int l1 = a.length();
  int l2 = b.length();
  string s1,s2;
  if(l1>l2)
  {
    s1=a;
    s2=b;
    s2.insert(s2.begin(), s1.length()-s2.length(),'0');
  }
  else if(l2>l1)
  {
    s1=b;
    s2=a;
    s2.insert(s2.begin(), s1.length()-s2.length(),'0');
  }
  else
  {
    s1=a;
    s2=b;
  }

  int l = s1.length();
  int i;
  string ans;
  int x;
  // sscanf(s1,"%d",&x);
  // cout<<x<<endl;
  int s, c;
  c=0;
  for(i=0;i<l;i++)
  {
    int n1 = s1[i] - '0';
    int n2 = s2[i] - '0';
    s = ((n1^n2)^c);
    c = ((n1 & n2) | (n1 & c)) | (n2 & c);
    ans[i] = s;
  }

  // cout<<s1<<" "<<s2<<endl;
  return ans;
}

int main()
{
  string s1,s2;
  cin>>s1;
  cin>>s2;
  string ans = adder(s1,s2);
  cout<<ans<<endl;
}
