class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (const auto& num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int count = 0;
                while (numSet.find(num + count) != numSet.end()) {
                    count++;
                }
                res = max(res, count);
            }           
        }
        return res;
    }
};
