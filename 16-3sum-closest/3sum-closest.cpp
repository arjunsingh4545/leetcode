class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end()); // Step 1: Sort the array
        int closest_sum = nums[0] + nums[1] + nums[2]; // Initialize closest sum

        for (size_t i = 0; i < nums.size() - 2; ++i) { // Step 2: Iterate through the array
            int left = i + 1; // Left pointer
            int right = nums.size() - 1; // Right pointer

            while (left < right) { // Step 3: Two-pointer technique
                int current_sum = nums[i] + nums[left] + nums[right];

                // Check if we found a closer sum
                if (std::abs(current_sum - target) < std::abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    left++; // Move left pointer to the right
                } else if (current_sum > target) {
                    right--; // Move right pointer to the left
                } else {
                    return current_sum; // Exact match found
                }
            }
        }

        return closest_sum; // Step 5: Return the closest sum
    }
};