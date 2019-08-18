#include <stdio.h>
int main()
{
  int i;
  char s[] = "Goldman Sachs";
  for(i=0;s[i];++i);
  int j =0;
  while(s[j++]);
  printf("%d %d",i,j);
}
