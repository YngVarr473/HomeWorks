class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result{};
        
        for (int i = 0; i < nums.size(); i++) {
            int k = 0;
            for (int j = 0; j < nums.size(); i++) {
                k = nums[j] + nums[i];
                if (k == target) {
                    result.push_back(nums[i]);
                    result.push_back(nums[j]);
                }
            }
        }
        return result;
    }
};
