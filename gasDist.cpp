#include<bits/stdc++.h>
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
  int gas = accumulate(A.begin(),A.end(),0);
  int dist = accumulate(B.begin(),B.end(),0);
  if(gas < dist )
    return -1;
  int i,ind=0;//A=gas and B = Dist
  int tot_A = A[i];
  int tot_B = B[i];
  for(i=1;i<A.size();i++)
  {
    if(tot_A>=tot_B)
    {
      tot_A+=A[i];
      tot_B+=B[i];
    }
    else
    {
      tot_A = A[i];
      tot_B = B[i];
      ind = i;
    }
  }
  return ind;
}
