class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }
        unordered_map<char, int> count1;

        for (char c : s1) {
            count1[c]++;
        }
        int need = count1.size();

        for (int i = 0; i < s2.length(); i++) {
            int have = 0;
            unordered_map<char, int> count2;
            for (int j = i; j < i + s1.length(); j++) {
                char c = s2[j];

                count2[c]++;

                if (count2[c] > count1[c]) {
                    break;
                }

                if (count2[c] == count1[c]) {
                    have++;
                }

                if (have == need) {
                    return true;
                }
            }
        }
        return false;
    }
};
