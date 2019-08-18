#include <stdio.h>
#include <stdlib.h>
int n;

void preprocess(int b[n][n],int a[])
{
  int i,j;
  for(i=0;i<n;i++)
  {
    int flag = 1;
    int num = a[i];
    while(num>0)
    {
      int r = num%10;
      for(j=0;j<n;j++)
      {
        if(i==j) continue;

        else
        {
          int num2 = a[j];
          while(num2>0)
          {
            int r2 = num2%10;
            if(r == r2)
            {
              // printf("for %d & %d, matching digit is %d\n",a[i],a[j],r);
              flag = 0;
              // b[i][j] = flag;
              break;
            }
            num2/=10;
          }
        }
      }
      num/=10;
    }
    b[i][j] = flag;
    flag = 1;
  }
}
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {

    scanf("%d",&n);
    int a[n];
    int b[n][n];
    int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        b[i][j] = -1000;
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
      b[i][i]=-1;
    }
    preprocess(b,a);
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        printf("%d ",b[i][j]);
      printf("\n");
    }
  }
}
