#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> fin;
void sieve(int n, int lim)
{
  // cout<<"lol"<<endl;
  int num[n+1];
  num[0]=0;
  num[1]=0;
  num[2]=1;
  int i;
  for(i=2;i<=n;i++)
  {
    num[i] = 1;
  }
  // cout<<"init"<<endl;
  for(i=2;i<=lim;i++)
  {
    if(num[i]==0)
      continue;
    else if(num[i] = 1)
    {
      int j = 2;
      int temp = i*j;
      while(temp<=n)
      {
        num[temp] = 0;
        j++;
        temp=i*j;
      }
    }
  }
  for(i=0;i<=n;i++)
  {
    if(num[i] == 1)
    {
      cout<<i<<" ";
      fin.push_back(i);
    }
  }
  cout<<endl;

}
int main()
{
  int n;
  cin>>n;
  int lim = sqrt(n);
  // cout<<lim<<endl;
  sieve(n,lim);
  // for(auto x:fin)
  //   cout<<x<<" ";
  // for(int i=0; i<fin.size(); ++i)
  //   std::cout << fin[i] << ' ';
  // cout<<endl;
}
