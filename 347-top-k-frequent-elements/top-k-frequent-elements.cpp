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
        unordered_map<int,int> numFreq;
        for(auto i : nums) {
            numFreq[i]++;
        }

        priority_queue<heapNode, vector<heapNode>, greater<heapNode>> minHeap;

        for(auto &[num,count] : numFreq) {
            minHeap.emplace(num,count);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        vector<int> res;
        while(!minHeap.empty()) {
            res.push_back(minHeap.top().num);
            minHeap.pop();
        }
        return res;
    }
};