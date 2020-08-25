// find a sequence of numbers varying in only one bit, given n- total number of bits
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2

vector<int> Solution::grayCode(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> res;
    for(int i = 0;i< (1<<n);i++)
    {
        res.push_back(i ^(i>>1));
    }
    return res;
}
