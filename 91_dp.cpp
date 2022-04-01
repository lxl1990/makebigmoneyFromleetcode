// /*
//     dp[i]][j]代表i到j有效解码数
//     dp[i][j] = dp[i][i] * dp[i+1][j] + isValid(i, i + 1)*dp[i+2][j]
// */
// class Solution {
// private:
//     int isValid(string& s, int i, int j) {
//         if (i == j) {
//             return s[i] == '0' ? 0 : 1;
//         }
//         if (i + 1 == j) {
//             if (s[i] == '0') return 0;
//             if (s[i] == '2' && s[j] >'6') return 0;
//             if (s[i] > '2') return 0;
//             return 1;
//         }
//         return 0;
//     }
// public:
//     int numDecodings(string s) {
//         int n = s.size();
//         if (n == 0) return 0;
//         vector<vector<int>> dp(n, vector<int>(n, 0));
//         for (int len = 0; len < n; len++) {
//             for (int i = 0; i + len < n; i++) {
//                 int j = i + len;
//                 // cout << "i: " << i <<", j: " << j << endl; 
//                 if (len == 0) {
//                     dp[i][j] = isValid(s, i, i);
//                 } else if (len == 1) {
//                     dp[i][j] = isValid(s, i, j) + isValid(s, i, i) * isValid(s, j, j);
//                 } else {
//                     dp[i][j] = dp[i][i] * dp[i + 1][j] + isValid(s, i, i + 1) * dp[i + 2][j];
//                 }
//             }
//         }
//         return dp[0][n-1];
//     }
// };




/*
    dp[i] 代表0-i解码方法数
    如果s[i] == '0', if s[i-1] in ('1', '2') then dp[i] = dp[i - 2]; else return 0;
    if s[i-1] == '1' or (s[i-1] = '2' and s[i] in ('1'-'6') then dp[i] = dp[i-1] + dp[i-2])
    else dp[i] = dp[i-1]
*/
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (s[0] == '0') return 0;
        int pre = 1, ppre = 1;
        for (int i = 1; i < n; i++) {
            int cur = 0;
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i -1] == '2') {
                    cur = ppre;
                } else {
                    return 0;
                }
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6')) {
                cur = pre + ppre;
            } else {
                cur = pre;
            }
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};
