class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> order;

        for (const auto& st : strs) {
            string sortedS = st;
            sort(sortedS.begin(), sortedS.end());
            order[sortedS].push_back(st);
        }

        vector<vector<string>> res;
        for (const auto& ord : order) {
            res.push_back(ord.second);
        }
        return res;
    }
};
