// return permutations

vector<vector<int> > ans;
void permutate(vector<int> A, int l, int r)
{
    if(l==r)
        ans.push_back(A);
    else
    {
        for(int i = l;i<r; i++)
        {
            swap(A[i],A[l]);
            permutate(A,l+1,r);
            swap(A[i],A[l]);
        }
    }

}

vector<vector<int> > Solution::permute(vector<int> &A) {
    ans.clear();
    int l = 0;
    int r = A.size();
    permutate(A,l,r);
    return ans;
}
