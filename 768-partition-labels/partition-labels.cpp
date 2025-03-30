class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char ,int> lastOccurences;
        for(int i=0 ; i < s.size() ; i++) lastOccurences[s[i]] = i;

        vector<int> res;
        int currentEnd = 0;
        int partitionStart =0;

        for(int i=0 ; i < s.size() ; i++) {
            currentEnd = max(currentEnd  , lastOccurences[s[i]]);
            if(i == currentEnd) {
                res.push_back(currentEnd - partitionStart +1);
                partitionStart = i+1;
            }
        }
        return res;
    }
};