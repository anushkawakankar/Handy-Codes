// Given a collection of intervals, merge all overlapping intervals.
//
// For example:
//
// Given [1,3],[2,6],[8,10],[15,18],
//
// return [1,6],[8,10],[15,18].
//
// Make sure the returned intervals are sorted.


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool func(Interval a,Interval b)
{
    if(a.start<b.start)
        return true;
    else if(a.start==b.start)
    {
        if(a.end<b.end)
            return true;
    }
    return false;
}
bool overlap(Interval a,Interval b)
{
    if(max(a.start,b.start)>min(a.end,b.end))
        return false;

    return true;
}
void update(Interval &a,Interval b)
{
    a.start=min(a.start,b.start);
    a.end=max(a.end,b.end);
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(),A.end(),func);
    vector<Interval> vec;
    vec.push_back(A[0]);
    Interval temp;
    for(int i=1;i<A.size();i++)
    {
        temp=A[i];
        if(overlap(vec[vec.size()-1],temp))
            update(vec[vec.size()-1],temp);
        else
            vec.push_back(temp);
    }
    return vec;
}
