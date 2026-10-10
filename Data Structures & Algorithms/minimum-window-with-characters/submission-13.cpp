class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT, window;

        for (char c : t) {
            countT[c]++;
        }
        int l = 0;
        int need = countT.size();
        int have = 0;
        int resLen = INT_MAX;
        pair<int, int> res = {-1, -1};

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        if (resLen == INT_MAX) {
            return "";
        } else {
            return s.substr(res.first, resLen);
        }
    }
};
