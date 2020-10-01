// largest rect w only ones, but you can permute the columns 

int Solution::solve(vector<vector<int> > &A) {
    for(int i=1;i<A.size();i++) //STORING THE COUNT OF CONSECUTIVE 1’S
        for(int j=0;j<A[i].size();j++)
            if(A[i][j]) A[i][j]+=A[i-1][j];
                int res=0;
    for(int i=0;i<A.size();i++){ //FIND COLWISE MAX AREA
        sort(A[i].begin(),A[i].end(),greater());
    for(int j=0;j<A[i].size();j++)
        res=max(res,A[i][j]*(j+1));}
    return res;
}
