#include <bits/stdc++.h>

using namespace std;

int num_partitions(vector<int> &A, vector<int> &B){
    int n = A.size();
    int m = B.size();
    for(int i=1;i<n;i++){
        A[i] = A[i] + A[i-1];
    }
    for(int i=1;i<m;i++){
        B[i] = B[i] + B[i-1];
    }

    int res = 0;
    for(int i=0;i<min(n,m)-1;i++){
        if(A[i] == A[n-1]-A[i] && B[i] == B[m-1]-B[i] && A[i]==B[i]){
            // cout << i << " ";
            res++;
        }
    }
    // cout << "\n";
    return res;
}

int main(){
    vector<int> A = {3, 4, 0, 1, -1, 5, 2};
    vector<int> B = {2, 0, 0, 0, 1, 1};
    cout << num_partitions(A, B) << endl;
    return 0;
}