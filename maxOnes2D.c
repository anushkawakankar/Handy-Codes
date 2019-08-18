#include <stdio.h>
#include <stdlib.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n];
    int i,j;
    int max=0,maxRow=0;
    for(i=0;i<m;i++)
    {
      int count=0;
      for(j=0;j<n;j++)
      {
        scanf("%d",&a[i][j]);
        if(a[i][j]==1)
          count++;
      }
      if(count>max)
      {
        max = count;
        maxRow = i;
      }
    }
    printf("%d\n",maxRow);
  }
}
