// Given three sorted arrays A, B and Cof not necessarily same sizes.
//
// Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
// i.e. minimize | max(a,b,c) - min(a,b,c) |.
//
// Example :
//
// Input:
//
// A : [ 1, 4, 5, 8, 10 ]
// B : [ 6, 9, 15 ]
// C : [ 2, 3, 6, 6 ]
// Output:
//
// 1
// Explanation: We get the minimum difference for a=5, b=6, c=6 as | max(a,b,c) - min(a,b,c) | = |6-5| = 1.



int max(int a, int b)
{
    if(a>b) return a;
    return b;
}

int mini(int a, int b)
{
    if(a>b) return b;
    return a;
}


int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i=0,j=0,k=0;
    int min=100000;
    while(i<A.size() &&j<B.size() &&k<C.size() ){
        int diff=max(max(A[i],B[j]),C[k])-mini(mini(A[i],B[j]),C[k]);
        if(diff<min){
            min=diff;
        }
        if(A[i]<=B[j]&&A[i]<=C[k]){
            i++;
        }else if(B[j]<=C[k]&&B[j]<=A[i]){
            j++;
        }else{
            k++;
        }
    }
    return min;
}
