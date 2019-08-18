#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a[100];
  scanf("%[^\n]s",&a[0]);
  // printf("%s\n",a);
  char* p = &a[0];
  int l = strlen(a);
  int i;
  int j;
  int end = l-1;
  for(i=l-2;i>=0;i--)
  {
    if(a[i] == ' ' || i == 0)
    {
      // printf("found space\n");
      for(j=i;j<=end;j++)
        printf("%c",a[j]);
      end = i;
    }
    printf(" ");

  }
  printf("\n");
}
