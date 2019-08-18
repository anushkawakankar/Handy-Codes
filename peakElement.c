#include <stdio.h>
#include <stdlib.h>

int findPeakFunc(int* nums, int l, int h, int numsSize)
{
  // printf("%d\n",numsSize);
  if(h<l)
    return -1;
  // printf("checking from %d to %d\n",*(nums+l),*(nums+h));
  int m = (l+(numsSize-1))/2;
  // printf("checking for %d\n",*(nums+m));
  if(*(nums+m)>=*(nums+m+1) && *(nums+m)>=*(nums+m-1))
    return m;
  else
  {
    if((*nums+m)>=*(nums+m+1))
      return findPeakFunc(nums, l, m-1, numsSize);
    else
      return findPeakFunc(nums, m+1, h, numsSize);
  }
}
int findPeakElement(int* nums, int numsSize)
{
  if(*nums > *(nums+1))
    return 0;
  else if(*(nums+numsSize-1) > *(nums+numsSize-2))
    return numsSize-1;
  return findPeakFunc(nums, 0, numsSize-1 , numsSize);
}

int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  int i;
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  int* p = &a[0];
  int ans = findPeakElement(p,n);
  printf("%d\n",ans);
}
