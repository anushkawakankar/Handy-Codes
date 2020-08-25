// You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:<ul>
//
// LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
//
// RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.
//
// Write a program to find the maximum special product of any integer in the array.
//
// Input: You will receive array of integers as argument to function.
//
// Return: Maximum special product of any integer in the array modulo 1000000007.
//
// Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.
//
// Constraints 1 <= N <= 10^5 1 <= A[i] <= 10^9


int Solution::maxSpecialProduct(vector<int> &A) {
    long long int i,n;
    long long int rspl,lspl;
    long long int maxspl=0;
    long long int x=1000000007;
    long long int curspl;
    n = A.size();
    vector<long long int> Lspl;
    vector<long long int> Rspl;
    Lspl.resize(n);
    Rspl.resize(n);
    stack<long long int> st;
    stack<long long int> st1;

    for(i=0;i<n;i++){
        while(!st.empty()){
            if(A[st.top()] <= A[i])
                st.pop();
            else
                break;
        }

        if(st.empty())
            Lspl[i] = 0;
        else
            Lspl[i] = st.top();

        st.push(i);
    }


    for(i=n-1;i>-1;i--){
        while(!st1.empty()){
            if(A[st1.top()] <= A[i])
                st1.pop();
            else
                break;
        }

        if(st1.empty())
            Rspl[i] = 0;
        else
            Rspl[i] = st1.top();
        st1.push(i);
    }


    maxspl = 0;
    for(i=0;i<n;i++){
         curspl = Lspl[i]*Rspl[i];;
        if(maxspl < curspl)
            maxspl = curspl;
    }

    return maxspl%x;
}
