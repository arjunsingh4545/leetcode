class Solution {
    struct heapNode {
        int num;
        int count;
        heapNode(int num , int count) : num(num) , count(count) {}

        bool operator>(const heapNode& other) const {
            return count > other.count;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) freq[n]++;
        priority_queue<pair<int, int>> pq;
        for (auto& [num, count] : freq) pq.emplace(count, num);
        vector<int> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};