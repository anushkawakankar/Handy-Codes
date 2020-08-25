// Print lexicographically sorted subsets of numbers which have duplicates

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    int size= A.size();
    vector<vector<int> > result;

    for(int i=0;i<pow(2,size);i++)
    {
        vector<int> res;
        for(int j=0;j<size;j++)
        {
            if(i>>j&1)
            {
                res.push_back(A[j]);
            }

        }
        if(find(result.begin(),result.end(),res)== result.end())
            result.push_back(res);

    }

    sort(result.begin(),result.end());
    return result;
}
