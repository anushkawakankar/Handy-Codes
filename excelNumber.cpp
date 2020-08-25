//Given a string, print its excel title numbr. A -> 1, AA -> 27

int Solution::titleToNumber(string A) {
    int ans = 0;
    int s = A.size();

    for( int i=1; i<=s; i++ ){

        ans += pow(26,s-i) * ( (int)A[i-1] - 64 );
    }

    return ans;
}
