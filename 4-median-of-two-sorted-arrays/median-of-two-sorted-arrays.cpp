class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         std::vector<int> merged;
        std::merge(nums1.begin() , nums1.end() , nums2.begin() , nums2.end() , std::back_inserter(merged));
        int n = merged.size();
        if(n % 2 == 0) {
            return (merged[n/2] + merged[n/2 - 1]) / 2.0;
        }
        return merged[n/2];
    }
};