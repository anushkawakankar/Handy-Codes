// Problem statement #2

// Matrix - N*N
// Start: topmost, left - initial -> bottom row. (end at any element in bottom row).
// 2 valid moves: Either down move or right diagonal down move. move one step at a time. find the max path weight. 

// Example:
// 1 2 9
// 4 8 6
// 3 11 7

int dp[n][n];
int maxPath(int mat[n][n])
{
    dp[1][0] = mat[0][0] + mat[1][0];
    dp[[1][1] = mat[0][0] + mat[1][1];
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j< n; j++)
        {
            if(i == 1 && j == 0 || i == 1 && j == 1) continue;
            if(i==0) dp[i][j] = mat[i][j];
            if(j==0) dp[i][j] = mat[i][j] + dp[i-1][j];
            dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    int max = INT_MIN;
    for(int i = 0; i<n ; i++)
    {
        if(dp[n-1][i] > max) max = dp[n-1][i];
    }
    return max;
}



