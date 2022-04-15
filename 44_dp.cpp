/*
    Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

    '?' Matches any single character.
    '*' Matches any sequence of characters (including the empty sequence).
    The matching should cover the entire input string (not partial).

    Input: s = "cb", p = "?a"
    Output: false
    Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
    if p[j] == '?' or s[i] == p[j]
        dp[i][j] = dp[i-1][j-1]
    elif p[j] == '*'
        dp[i][j] = dp[i-1][j] || dp[i][j-1]
    else
        dp[i][j] = false
*/

//class Solution {
//public:
//    bool isMatch(string s, string p) {
//        int len1 = s.size(), len2 = p.size();
//        if (len1 == 0 && len2 == 0) return true;
//        vector<bool> dp(len2 + 1, false);
//        int i = 0;
//        while(p[i] == '*') {
//            dp[++i] = true;
//        }
//        for (int i = 0; i < s.size(); i++) {
//            bool pre = i == 0 ? true : false;
//            for (int j = 0; j < p.size(); j++) {
//                bool tmp = dp[j + 1];
//                if (p[j] == '?' || p[j] == s[i]) {
//                    dp[j + 1] = pre;
//                } else if (p[j] == '*') {
//                    dp[j + 1] = dp[j + 1] || dp[j];
//                } else {
//                    dp[j + 1] = false;
//                }
//                pre = tmp;
//                cout << "i: " << i + 1 << ", j: " << j + 1 << ", val: " << dp[j + 1] << endl;
//            }
//        }
//        return dp[len2];
//    }
//};


/*
    贪心，双指针
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        auto charMatch = [](char s, char p) {
            return p == s || p == '?';
        };
        while(!p.empty() && !s.empty() && p.back() != '*') {
            if (charMatch(s.back(), p.back())) {
                s.pop_back();
                p.pop_back();
            } else {
                return false;
            }
        }
        if (p.empty()) {
            return s.empty();
        }
        int scurIndex = 0, pcurIndex = 0;
        int slastIndex = -1, plastIndex = -1;
        while (scurIndex < s.size() && pcurIndex < p.size()) {
            if (p[pcurIndex] == '*') {
                slastIndex = scurIndex;
                plastIndex = pcurIndex;
                pcurIndex++;
            } else if (charMatch(s[scurIndex], p[pcurIndex])) {
                pcurIndex++;
                scurIndex++;
            } else if (slastIndex != -1) {
                scurIndex = slastIndex + 1;
                pcurIndex = plastIndex + 1;
                slastIndex = scurIndex;
            } else {
                return false;
            }
        }
        auto allStars = [&](int cur, int len) {
            while (p[cur] == '*') {
                cur++;
            }
            return cur == len;        
        };
        return allStars(pcurIndex, p.size());
    }
};


"ab"
"?*"
