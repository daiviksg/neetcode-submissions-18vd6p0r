class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> charset;

        for (const auto& str : strs) {
            string sortedS = str;
            sort(sortedS.begin(), sortedS.end());
            charset[sortedS].push_back(str);
        }

        vector<vector<string>> res;

        for (const auto& ch : charset) {
            res.push_back(ch.second);
        }
        return res;
    }
};
