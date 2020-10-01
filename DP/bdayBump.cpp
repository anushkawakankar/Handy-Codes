// It’s Tushar’s birthday today and he has N friends.
//
// Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].
//
// Today being his birthday, his friends have planned to give him birthday bombs (kicks).
//
// Tushar's friends know Tushar's pain bearing limit and would hit accordingly.
//
// If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength
// (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum.



vector<int> Solution::solve(int A, vector<int> &B) {
    int n=B.size();

    vector<int> dp(A+1,0),index(A+1);

    for(int i=0;i<=A;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=B[j])
            {
                if(dp[i-B[j]]+1 > dp[i])
                {
                    dp[i]=dp[i-B[j]]+1;
                    index[i]=j;
                }
            }
        }
    }

    vector<int> ans;

    int val=A;

    while(val>0 && val>=B[index[val]])
    {
        ans.push_back(index[val]);
        val=val-B[index[val]];
    }

    return ans;
}
