/*
    dp[i][j] indicates the left-most starting index of the minimum substring part of s1[:i] which covers s2[:j]
    dp[i][j] = s1[i] == s2[j] ? dp[i-1][j-1] : dp[i-1][j]

*/
// class Solution {
// public:
//     string minWindow(string s1, string s2) {
//         int n1 = s1.size(), n2 = s2.size();
//         vector<int> dp(n2, -1);
//         dp[0] = s1[0] == s2[0] ? 0 : -1;
//         string ret = "";
//         int maxLen = n1 + 1;
//         if (dp[n2 - 1] != -1) {
//             maxLen = 1;
//             ret = s1.substr(0, maxLen);
//         }
//         for (int i = 1; i < n1; i++) {
//             int pre = dp[0];
//             dp[0] = s1[i] == s2[0] ? i : dp[0];
//             for (int j = 1; j < n2; j++) {
//                 int tmp = dp[j];
//                 dp[j] = s1[i] == s2[j] ? pre : dp[j];
//                 pre = tmp;
//             }

//             if (dp[n2 - 1] != -1 && maxLen > i - dp[n2 - 1] + 1) {
//                 maxLen = i - dp[n2 - 1] + 1;
//                 ret = s1.substr(dp[n2 - 1], maxLen);
//             }
//         }

//         return ret;
//     }
// };


/*
next[i][letter] indicates the left-most index of s1[i:] whose value equals letter

next[i][letter] = s1[i] == letter ? i : next[i + 1][letter]
*/

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> next(n1, vector<int>(26, -1));
        next[n1 - 1][s1[n1 - 1] - 'a'] = n1 -1;
        for (int i = n1 - 2; i >= 0; i--) {
            for (int k = 0; k < 26; k++) {
                next[i][k] = s1[i] == 'a' + k ? i : next[i + 1][k];
            }
        }
        vector<vector<int>> windows;
        for (int i = 0; i < n1; i++) {
            if (s1[i] == s2[0]) {
                windows.emplace_back(vector<int>{i, i});
            }
        }
        for (int i = 1; i < s2.size(); i++) {
            int letter = s2[i] - 'a';
            for (int j = 0; j < windows.size(); j++) {
                auto& window = windows[j];
                if (window[1] < n1 - 1 && next[window[1]+1][letter] >= 0) {
                    window[1] = next[window[1]+1][letter];
                } else {
                    window[0] = window[1] = -1;
                    break;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < windows.size(); i++) {
            if (windows[i][0] == -1) break;
            if (ans.size() == 0 || windows[i][1] - windows[i][0] < ans[1] - ans[0]) {
                ans = windows[i];
            }
        }
        return ans.size() > 0 ? s1.substr(ans[0], ans[1] - ans[0] + 1) : "";
    }
};
