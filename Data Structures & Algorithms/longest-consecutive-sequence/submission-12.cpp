class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int res = 0;

        for (const auto& num : nums) {
            if (numSet.find(num - 1) == numSet.end()) {
                int count = 1;
                while (numSet.find(num + count) != numSet.end()) {
                    count++;
                    
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
