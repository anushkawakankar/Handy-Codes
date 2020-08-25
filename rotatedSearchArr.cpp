int Solution::search(const vector<int> &A, int target) {

   int l=0;
   int r =A.size()-1;

   while(l<=r)
   {
       int mid = (l+r)/2;
       if(target==A[mid])
       {
           return mid;
       }
       if(A[mid]>=A[l])
       {
           if(target>=A[l] && target<=A[mid])
                r = mid - 1;
           else
               l = mid+1;
       }
       else
       {
           if(target>=A[mid] && target<=A[r])
                l=mid+1;
            else
                r = mid-1;
       }

   }
   return -1;
}
