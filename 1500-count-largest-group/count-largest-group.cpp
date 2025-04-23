class Solution {
    int sumOfDigits(int n) {
        int sum = 0;
        while(n > 0 ) {
            sum += n %10;
            n = n/10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        vector<vector<int>> groups;
        unordered_map<int,int> sumMap;

        for(int i=1 ; i <= n; i++) {
            sumMap[sumOfDigits(i)]++;
        }

        int maxSize =0;
        for(auto& entry : sumMap) {
            if(maxSize < entry.second) {
                maxSize = entry.second;
            }
        }

        int largestGroupCount =0;
        for(auto& entry : sumMap) {
            if(entry.second == maxSize) largestGroupCount++;
        }
        return largestGroupCount;
    }
};