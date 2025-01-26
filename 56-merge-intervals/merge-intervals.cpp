class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        // Sort the intervals based on the starting times
        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(auto& interval : intervals) {
            auto& lastMerged = res.back();
            if(lastMerged[1] >= interval[0]) {
                lastMerged[1] = max(interval[1] , lastMerged[1]);
            } else {
                res.push_back(interval);
            }
        }
        return res;
    }
};