#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestPalindrome(char* s)
{
  int i = 0,l = 0;
  while(*(s+i) != '\0')
  {
    i++;
    l++;
  }
  int temp[l][l];
  int j;
  for(i=0;i<l;i++)
    for(j=0;j<l;j++)
      temp[i][j] = 0;

  for(i=0;i<l;i++)
    temp[i][i] = 1;

  int max = 1;
  int start = 0;
  for(i=0;i<l-1;i++)
  {
    if(*(s+i) == *(s+i+1))
    {
      temp[i][i+1] = 1;
      start = i;
      max = 2;
    }
  }
  int k;
  for(j=3;j<=l;j++)
  {
    for(k=0;k<l-j+1;k++)
    {
      int x = j+k-1;
      if(temp[k+1][x-1] == 1 && *(s+k) == *(s+x))
      {
        temp[k][x] = 1;
        if(j>max)
        {
          start = k;
          max = j;
        }
      }

    }
  }
  return max;
}
int main()
{
  char str[1000];
  scanf("%s",&str[0]);
  char* p = &str[0];
  printf("%d\n",longestPalindrome(p));
}
