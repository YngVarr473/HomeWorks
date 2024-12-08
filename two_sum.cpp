#include <iostream>
#include <vector>


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result();
        
        for (int i = 0; i < nums.size(); i++) {
             if (i - 1 >= 0) {

            if (nums[i - 1] > 0 && nums[i] > 0) {
                if (nums[i - 1] + nums[i] == target) {
                    result.push_back(nums[i - 1], nums[i])
                }
            }
        } else if (nums[i] + nums[i + 1] == target) {
                result.push_back(nums[i], nums[i + 1])
            }

        return result;
    }
}
}
