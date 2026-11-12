class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visit;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (const auto& pre : prerequisites) {
            preMap[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs) {
        if (visit.count(crs)) {
            return false;
        }

        if (preMap[crs].empty()) {
            return true;
        }

        visit.insert(crs);
        for (int pre : preMap[crs]) {
            if (!dfs(pre)) {
                return false;
            }
        }

        visit.erase(crs);
        preMap[crs].clear();
        return true;      
    }
};
