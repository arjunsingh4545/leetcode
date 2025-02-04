class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();

        // First pass: Place each number in its right place
        for (int i = 0; i < n; ++i) {
            // While the current number is in the range [1, n] and is not in its correct position
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap nums[i] with nums[nums[i] - 1]
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Second pass: Find the first missing positive
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1; // The first missing positive integer
            }
        }

        // If all numbers from 1 to n are present, return n + 1
        return n + 1;

    }
};