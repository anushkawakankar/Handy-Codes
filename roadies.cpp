#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int b[100][100];

int checkpair(int num1, int num2)
{
    string s1 = to_string(num1);
    string s2 = to_string(num2);

    for (int i = 0; i < s1.size(); i++)
        for (int j = 0; j < s2.size(); j++)
            if (s1[i] == s2[j])
                return 0;

    return 1;
}


int findMax(int a[],int ind,int n)
{
  int i,j;
  int c[n][n];
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      
    }
  }
}

int compare(const void* a, const void* b)
{
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return -1;
	else if (*x < *y)
		return 1;

	return 0;
}


void preprocess(int a[],int n)
{
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(i!=j)
        b[i][j] = checkpair(a[i],a[j]);
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
    int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        b[i][j] = -1000;
    for(i=0;i<n;i++)
    {
      cin>>a[i];
      b[i][i]=-1;
    }
    qsort(a,n,sizeof(int),compare);
    // cout<<"   ";
    // for(i=0;i<n;i++)
    //   cout<<a[i]<<" ";
    // cout<<endl;
    preprocess(a,n);
    // for(i=0;i<n;i++)
    // {
    //   // cout<<a[i]<<" ";
    //   for(j=0;j<n;j++)
    //     cout<<b[i][j]<<" ";
    //   cout<<endl;
    // }
    int max = 0;
    for(i=0;i<n;i++)
    {
      int sum = findMax(a,i,n);
      max = (sum>max)?sum:max;
    }
    cout<<max<<endl;

  }
}
