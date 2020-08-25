// compute (x^y)%p
int Solution::pow(int x, int y, int p) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    long res = 1;

    long z = x % p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*z) % p;

        // y must be even now
        y = y>>1; // y = y/2
        z = (z*z) % p;
    }

    if(res>=0)
    return res%p ;

    return (p+res);
}
