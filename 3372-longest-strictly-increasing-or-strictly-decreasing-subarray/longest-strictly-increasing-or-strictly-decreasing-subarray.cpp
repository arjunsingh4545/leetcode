class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxLen = 1; // At least one element is there
        int currentIncreasingLen = 1;
        int currentDecreasingLen = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                currentIncreasingLen++;
                currentDecreasingLen = 1; // Reset decreasing length
            } else if (nums[i] < nums[i - 1]) {
                currentDecreasingLen++;
                currentIncreasingLen = 1; // Reset increasing length
            } else {
                // Reset both lengths if the current element is equal to the previous one
                currentIncreasingLen = 1;
                currentDecreasingLen = 1;
            }

            // Update maxLen with the maximum of current lengths
            maxLen = std::max(maxLen, std::max(currentIncreasingLen, currentDecreasingLen));
        }

        return maxLen;
    }
};