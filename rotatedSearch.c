#include <stdio.h>
#include <stdlib.h>

int binary(int* nums, int low, int high, int s)
{
  if (high < low)
       return -1;
   int mid = (low + high)/2 ;
   if (s == *(nums+mid))
       return mid;
   if (s > *(nums+mid))
       return binary(nums, (mid + 1), high, s);
   return binary(nums, low, (mid -1), s);
}
int findPivot(int* nums, int l, int h)
{
  if (h < l)  return 0;
   if (h == l) return l;

   int m = (l + h)/2;
   if (m < h && *(nums+m) > *(nums+m+1))
       return m;
   if (m > l && *(nums+m) < *(nums+m-1))
       return (m-1);
   if (*(nums+l) >= *(nums+m))
       return findPivot(nums, l, m-1);
   return findPivot(nums, m + 1, h);
}
int search(int* nums,int n,int s)
{
  int pivot = findPivot(nums,0,n-1);

    if(pivot == -1)
      return -1;

    else
    {
      if(*(nums+pivot)==s)
        return pivot;
      if(*(nums)<=s)
      {
        if(pivot>0)
          return binary(nums, 0, pivot-1, s);
        else
          return binary(nums, 0, n-1, s);
      }
      return binary(nums, pivot+1,n-1,s);
    }

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
  int s;
  scanf("%d",&s);
  int* nums = &a[0];
  printf("%d\n",search(nums,n,s));
}
