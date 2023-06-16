//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.



class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        if(l==1)
            return;
        k = k%l;
        for(int i = 0; i<(l-k); i++)
        {
            nums.push_back(nums[i]);
        }
        nums.erase(nums.begin(), nums.begin() + l-k);
    }
};
