//Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. witohut division

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        prefix[0] = 1;
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        suffix[n-1] = 1;
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        vector<int> ans(n);
        for(int i = 0;i <n ; i++)
        {
            ans[i] = prefix[i] * suffix[i];
        }
        return(ans);
    }
};
