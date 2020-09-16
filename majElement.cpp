// Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.

int Solution::majorityElement(const vector<int> &A)
{
    int i=1;
    int v1 = A[0];
    stack<int> s;
    s.push(A[0]);
    for(i=1;i<A.size();i++)
    {
        if(!s.empty() && s.top()!=A[i])
            s.pop();
        else
            s.push(A[i]);
    }
    return s.top();
}
