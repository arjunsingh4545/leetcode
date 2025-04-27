class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if(nums.size() < 3) return 0; 
        vector<int>::iterator it1=nums.begin(),it2= nums.begin()+1,it3 = nums.begin()+2;
        int countSub = 0;
        while(it3 != nums.end()) {
            if(*it2%2 == 0) {
                if(*it1+*it3 == (*it2/2)) {
                    countSub++;
                }
            }
            it1++;
            it2++;
            it3++;
        }
        return countSub;
    }
};