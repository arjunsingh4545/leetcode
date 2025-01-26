class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin() , nums.end() , target);
        if (left == nums.end() || *left != target) {
            return {-1, -1};
        }

        auto right = upper_bound(nums.begin() , nums.end() , target);
        return {static_cast<int>(left - nums.begin()), static_cast<int>(right - nums.begin() - 1)};
    }
};