class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> ans;
        std::unordered_map<std::string, std::vector<std::string>> keyToAnagrams;

        for (const string& str : strs) {
            string key = str;
            std::sort(key.begin() , key.end());
            keyToAnagrams[key].push_back(str);
        }

        for (const auto& [_, anagrams] : keyToAnagrams)
            ans.push_back(anagrams);

        return ans;
    }
};