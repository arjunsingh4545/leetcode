class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    vector<vector<int>> vecs(nums.size()+1);
    vector<int> ans;
    for (int i : nums)
        mp[i]++;
    for (auto e : mp)
        vecs[e.second].push_back(e.first);
    for (auto it = vecs.rbegin(); it != vecs.rend() && ans.size() < k; it++)
    {
        for (auto i : *it)
        {
            ans.push_back(i);
            if (ans.size() > k)
                break;
        }
    }
    return ans;
    }
};