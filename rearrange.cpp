#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a[100];
  scanf("%s",&a[0]);
  int l = strlen(a);
  int i;
  int freq[26];
  for(i=0;i<26;i++)
    freq[i] = 0;
  int max = 0;
  for(i=0;i<l;i++)
  {
    int num = (int)a[i] - 97;
    freq[num]++;
    if(freq[num]>max)
      max = freq[num];
    
  }

}
