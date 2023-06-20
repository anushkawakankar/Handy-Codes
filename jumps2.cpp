//Each element nums[i] represents the maximum length of a forward jump from index i. Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i = 1; i< nums.size(); i++)
            nums[i] = max(nums[i]+i, nums[i-1]);
        int ind = 0;
        int ans = 0;
        while(ind < nums.size() - 1)
        {
            ans++;
            ind = nums[ind];
        }
        return(ans);
    }
};
