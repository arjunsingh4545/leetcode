class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> complementVector;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            for (int j = 0; j < complementVector.size(); j++) {
                if (nums[complementVector[j]] == complement) {
                    result.push_back(complementVector[j]);
                    result.push_back(i);
                    return result;
                }
            }
            complementVector.push_back(i);
        }

        return result;
    }
};