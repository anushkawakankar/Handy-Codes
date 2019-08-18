#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
  char a[100];
  scanf("%s",&a[0]);
  int k;
  scanf("%d",&k);
  int hash[26];
  int ones[26];
  int i;
  int l = strlen(a);
  for(i=0;i<26;i++)
  {
    hash[i] = 0;
    ones[i] = 2*l;
  }

  for(i=0;i<l;i++) //-97
  {
    int num = (int)a[i] - 97;
    hash[num]++;
    if(hash[num] == 1)
      ones[num] = i;
    else
      ones[num] = 2*l;
  }
  // for(i=0;i<26;i++)
  // {
  //   if(ones[i] < l)
  //     printf("%c ",a[ones[i]]);
  //
  // }
  // printf("\n");
  qsort(ones,26,sizeof(int),compare);
  if(ones[k-1] < l)
    printf("kth non repeating is %c\n",a[ones[k-1]]);
  else
    printf("k is more than repeating char\n");

}
