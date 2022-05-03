class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0;
        vector<int> pos(1 << 5, -2);
        pos[0] = -1;
        int preStatus = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                preStatus ^= 1;
            } else if (s[i] == 'o') {
                preStatus ^= 1 << 1;
            } else if (s[i] == 'e') {
                preStatus ^= 1 << 2;
            } else if (s[i] == 'i') {
                preStatus ^= 1 << 3;
            } else if (s[i] == 'u') {
                preStatus ^= 1 << 4;
            }
            if (pos[preStatus] != -2) {
                ans = max(ans, i - pos[preStatus]);
            } else {
                pos[preStatus] = i;
            }
        }
        return ans;
    }
};
