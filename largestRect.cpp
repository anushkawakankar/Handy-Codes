// Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.

int maxarea(vector<int> v)
{
int best=0,i,n=v.size(),low,high;

for(i=0;i<n;i++)
{
    high=i+1;
    low=i-1;
    while(v[low]>=v[i] && low>=0)
    {
        low--;
    }
    while(v[high]>=v[i] && high<n)
    {
        high++;
    }

    if( ((high-low-1)*v[i])>best)
    {
        best=((high-low-1)*v[i]);
    }

}

return best;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {

int i,k,j,n,m,ans;
n=A.size();
m=A[0].size();
ans=maxarea(A[0]);

for(i=1;i<n;i++)
{
    for(j=0;j<m;j++)
    {
        if(A[i][j]==0)
        {

        }
        else
        {
            if(A[i-1][j])
            {
                A[i][j]=A[i-1][j]+1;
            }


        }

    }

    ans=max(ans,maxarea(A[i]));

}

return ans;
}
