// Given n non-negative integers a1, a2, ..., an,
// where each represents a point at coordinate (i, ai).
// 'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
//
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
// Your program should return an integer which corresponds to the maximum area of water that can be contained


// Input : [1, 5, 4, 3]
// Output : 6
//
// Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3.
// So total area = 3 * 2 = 6


long long find(int start, int end, int n )
{
    return min(start,end)*n;
}

int Solution::maxArea(vector<int> &A) {

    vector<int>::iterator start, end;

    start = A.begin();
    int n = A.size();
    end = A.end();
    end--;
    int i =2;

    long long area = min(*start,*end)*(n-1);
    while(start<end){
        if(*start<=*end)
        {
            start++;
            area = max(find(*start, *end, n-i), area);
        }
        else{
            end--;
           area = max(find(*start, *end, n-i), area);

        }
        i++;
        //cout<<area<<endl;
    }
    return area;
}
