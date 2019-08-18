#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int n)
{
  if(n==1 || n==0)
    return 1;
  return n*fact(n-1);
}
int subsets(int n, int k)
{
    int num = fact(n+k-1);
    int den = fact(n) * fact(k-1);
    return num/den;
}
int sumofprime(int n, int* arr)
{
  int sum = 0;
  int i;
  for(i=0;i<n;i++)
  {
    int num = *(arr+i);
    while(num%2 == 0)
    {
      sum+=2;
      num/=2;
    }
    for(int j=3;j<sqrt(n);j+=2)
    {
      while(num%j == 0)
      {
        sum+= j;
        num/=j;
      }
    }
    if(num>2)
    {
      sum += num;
    }
  }
  return sum;
}

int primeSum(int k, int n, int* arr)
{
  int i;
  int sum = sumofprime(n,arr);
  sum = sum%(1000000);
  int ans = subsets(sum,k);
  ans = ans%(1000000007);
  return ans;
}
int main()
{
  int k,n;
  scanf("%d%d",&k,&n);
  int i;
  int a[n];
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  int *ptr = &a[0];
  printf("%d\n",primeSum(k,n,ptr));
}
