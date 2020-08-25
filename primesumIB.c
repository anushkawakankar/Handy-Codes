/**
 * @input A : Integer
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
void sieve(int n, int lim,int* num){
    // int num[n+1];
  num[0]=0;
  num[1]=0;
  num[2]=1;
  int i;
  for(i=2;i<=n;i++)
  {
    num[i] = 1;
  }
  // cout<<"init"<<endl;
  for(i=2;i<=lim;i++)
  {
    if(num[i]==0)
      continue;
    else if(num[i] = 1)
    {
      int j = 2;
      int temp = i*j;
      while(temp<=n)
      {
        num[temp] = 0;
        j++;
        temp=i*j;
      }
    }
  }
}
int* primesum(int A, int *len1,int a) {
    len1 = (int*)malloc(10*sizeof(int));
    int* p = (int*)malloc((A+1)*sizeof(int));
    // int a = sqrt(A);
    sieve(A, a, p);
    int i;
    int j = 0;
    int counter = 0;
    for(i=2;i<A;i++)
    {
        j = A-i;
        if(p[i] ==1 && p[j] == 1)
        {
            p[i] = 0;
            p[j] = 0;
            len1[counter] = i;
            len1[counter+1] = j;
            counter+=2;
            break;
        }
    }
    // for(i=0;i<counter;i++)
    //     printf("%d ",len1[i]);
    // printf("\n");

    return len1;
}
int main()
{
  int A,a;
  scanf("%d %d",&A,&a);
  int* ans = (int*)malloc(2*sizeof(int));
  ans = primesum(A,ans,a);
  int i;
  for(i=0;i<2;i++)
    printf("%d ",ans[i]);
  printf("\n");
}
