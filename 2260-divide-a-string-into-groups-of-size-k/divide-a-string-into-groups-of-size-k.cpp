class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for(int i=0 ; i < s.size() ; i += k) {
            string str = s.substr(i,k);
            while(str.size() < k) str += fill;
            res.push_back(str);
        }
        return res;
    }
};