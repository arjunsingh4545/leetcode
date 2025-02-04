class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxSum = 0;
        int currentSum = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i]; // Continue the ascending subarray
            } else {
                maxSum = std::max(maxSum, currentSum); // Update maxSum if needed
                currentSum = nums[i]; // Reset currentSum to the current element
            }
        }

        // Final check to update maxSum for the last ascending subarray
        maxSum = std::max(maxSum, currentSum);

        return maxSum;
    }
};