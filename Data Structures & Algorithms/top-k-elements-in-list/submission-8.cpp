class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numset;

        for (const auto& num : nums) {
            numset[num]++;
        }
        vector<pair<int, int>> res;

        for (const auto& num : numset) {
            res.push_back({num.second, num.first});
        }

        sort(res.rbegin(), res.rend());
        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(res[i].second);
        }
        return result;
    }
};
