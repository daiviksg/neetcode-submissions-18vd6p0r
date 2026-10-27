class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        backtrack(nums, subset, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& cur, int i) {
        if (i >= nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        backtrack(nums, cur, i + 1);
        cur.pop_back();
        backtrack(nums, cur, i + 1);
    }
};
