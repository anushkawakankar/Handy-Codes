// We define DP(i, j) as the minimum cost for making cuts Ai, Ai+1, …, Aj. Note that you are not making cuts Ai and Aj, but they decide the cost for us.
//
// For solving DP(i, j), we iterate k from i+1 to j-1, assuming that the first cut we make in this interval is Ak.
// The total cost required(if we make first cut at Ak) is Aj - Ai + DP(i, k) + DP(k, j).

vector<int> ans;

void find_ans(vector<vector<int>> pa, int l, int r)
{
    if(pa[l][r] == -1) return;
    else
    {
        ans.push_back(pa[l][r]);
        find_ans(pa, l, pa[l][r]);
        find_ans(pa, pa[l][r], r);
    }
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    int m = B.size();
    ans.clear();
    vector<int> B1(m+2);
    B1[0] = 0; B1[m+1] = A;
    for(int i = 0; i<m; i++) B1[i+1] = B[i];
    vector<vector<int>> dp(m+2, vector<int>(m+2, INT_MAX)), pa(m+2, vector<int>(m+2, -1));
    for(int i = m+1; i>=0; i--)
    {
        for(int j = 0; j<m+2; j++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
                continue;
            }
            if(i>j) continue;
            int cost = B1[j] - B1[i];
            for(int k = i+1; k<j; k++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j] + cost)
                {
                    dp[i][j] = dp[i][k] + dp[k][j] + cost;
                    pa[i][j] = k;
                }
            }
        }
    }

    find_ans(pa, 0, m+1);
    vector<int> final_ans(m);
    for(int i = 0; i<m; i++)
    {
        final_ans[i] = B[ans[i]-1];
    }
    return final_ans;
}
