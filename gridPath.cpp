/* Given AxB grid, move from top left corner to bottom right corner in how many paths?*/

int Solution::uniquePaths(int A, int B) {
    if(A==1 || B==1)
    {
        return 1;
    }

    return  uniquePaths(A-1, B) + uniquePaths(A, B-1);
}
