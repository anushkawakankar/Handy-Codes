#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}


int main() {
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    int s[n], e[n];
    int i;
    for(i=0;i<n;i++)
    {
      scanf("%d",&s[i]);
    }
    for(i=0;i<n;i++)
    {
      scanf("%d",&e[i]);
    }
    qsort(s,n, sizeof(int),compare);
    qsort(e,n, sizeof(int),compare);
    // for(i=0;i<n;i++)
    // {
    //   printf("%d ",s[i]);
    // }
    // printf("\n");
    // for(i=0;i<n;i++)
    // {
    //   printf("%d ",e[i]);
    // }
    // printf("\n");
    int flag = 0;
    for(i=0;i<n;i++)
    {
      if(e[i] >= s[i])
        continue;
      else
      {
        printf("LOSE\n");
        flag++;
        break;
      }
    }
    if(!flag)
    {
      printf("WIN\n");
    }
  }
  return 0;
}
