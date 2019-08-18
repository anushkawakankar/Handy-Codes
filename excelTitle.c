#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToTitle(int A)
{
  char a[1000000];
  int i = 0;
  while(A>0)
  {
    if(A<=26)
      a[i] = (char)(A+64);
    else
    {
      a[i] = 'A';
    }
    A-=26;
    i++;
  }
  a[i] = '\n';
  // char* p = &a[0];
  // return p;
  int l = strlen(a);
  int j = 0;
  for(j=0;j<l;j++)
  {
    printf("%c",a[j]);
  }
  // printf("\n");
}
int main()
{
  // char a[10];
  // scanf("%s",&a);
  // char* p = &a[0];
  // int i;
  // for(i=0;i<strlen(a)-2;i++)
  //   printf("%c",*(p+i));
  // printf("\n");
  int n;
  scanf("%d",&n);
  convertToTitle(n);


}
