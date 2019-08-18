#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
bool pal(int x)
{
  bool res;
  if(x<0)
    res = false;
  else if(x>=0 && x <10)
    res = true;
  else if(x>=10)
  {
    int n2 = x;
    long rev = 0;
    int r = 0;
    while(n2>0)
    {
      r = n2%10;
      rev = rev*10 + r;
      n2/=10;
    }
    // cout<<"reversed = "<<rev<<endl;
    if(rev==x)
      res = true;
    else
      res = false;
  }
  return res;
}

int main(){
  int n;
  cin>>n;
  bool res = pal(n);
  cout<<res<<endl;
}
