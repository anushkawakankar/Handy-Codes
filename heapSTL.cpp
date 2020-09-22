#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int> v;
  int temp;
  for(int i = 0;i<n;i++)
  {
    cin>>temp;
    v.push_back(temp);

  }
  make_heap(v.begin(),v.end());
  cout<<"Max elem : "<<v.front()<<endl;
  v.push_back(v.front()+10);
  make_heap(v.begin(),v.end());
  cout<<"Max elem : "<<v.front()<<endl;
  pop_heap(v.begin(),v.end());
  v.pop_back();
  cout<<"Max elem : "<<v.front()<<endl;
  
}
