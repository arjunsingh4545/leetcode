class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if (nums.size() < 3) return 0; 
        int countSub = 0;

        for (int i = 1; i < nums.size() - 1; i++) {
           if (nums[i] % 2 == 0) {
                // Check the condition
                if (nums[i - 1] + nums[i + 1] == nums[i] / 2) {
                    countSub++;
                }
            }
        }
        
        return countSub;
    }
};