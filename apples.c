#include <stdio.h>
#include <stdlib.h>
// int weightfreq[100];
int func(int lim, int n, int* apples){
  int i;
  // for(i=0;i<n;i++)
  //   printf("%d ",*(apples+i));
  int weightfreq[lim+1];
  for(i=0;i<=lim;i++)
    weightfreq[i]=0;
  int num =0;
  for(i=0;i<n;i++)
  {
    num = *(apples+i);
    // printf("%d ",num);
    weightfreq[num]++;
  }
  for(i=0;i<=lim;i++)
    printf("%d ",weightfreq[i]);
  int bagcount = 0;
  bagcount += weightfreq[lim];
  for(i=lim-1;i>=0;i--)
  {
    for(int j = 0;j<=i;j++)
    {
      while(weightfreq[i]>0 && weightfreq[j]>0)
      {
        if(i+j <= lim)
        {
          bagcount++;
          weightfreq[i]--;
          weightfreq[j]--;
        }
      }

    }
  }
  int left = 0;
  for(i=0;i<=lim;i++)
    left+= weightfreq[i];

  bagcount += (left%2 == 0)?(left/2):((left/2) + 1);
  return bagcount;
}

int main()
{
  int lim,n;
  scanf("%d%d",&lim,&n);
  int i;
  int a[n];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  int * ptr= &a[0];
  func(lim,n,a);
  // printf("%d\n",func(lim,n,a));
}
