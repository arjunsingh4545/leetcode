class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int64_t count = 0;
        int64_t sum = 0; // Use int64_t for larger sums
        int left = 0;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            // Calculate the score of the current subarray
            while (left <= right && (sum * (right - left + 1)) >= k) {
                sum -= nums[left];
                left++;
            }
            // All subarrays ending at 'right' and starting from 'left' to 'right' are valid
            count += (right - left + 1);
        }

        return count;
    }
};