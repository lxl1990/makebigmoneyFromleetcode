// class Solution {
// private:
//     int dfs(string& text, int left, int right) {
//         if (left > right) return 0;
//         int i = 1;
//         int len = right - left + 1;
//         while (i <= (len >> 1)) {
//             if (text.substr(left, i) == text.substr(right - i + 1, i)) {
//                 return 2 + dfs(text, left + i, right - i);
//             }
//             i++;
//         }
//         return 1;
//     }
// public:
//     int longestDecomposition(string text) {
//         int n = text.size();
//         return dfs(text, 0, n - 1);
//     }
// };


class Solution {
public:
    int longestDecomposition(string text) {
        int n = text.size();
        // cout << "n: " << n << endl;
        int left = (n >> 1) - 1;
        int right = (n + 1) >> 1;
        vector<int> dp(right, 1);
        if ((n & 1) == 0) dp[right - 1] = 1;
        for (int i = left; i >= 0; i--) {
            for (int j = i; j <= left; j++) {
                if (text.substr(i, j - i + 1) == text.substr(left + right - j, j - i + 1)) {
                    dp[i] = j + 1 >= dp.size() ? 2 : dp[j + 1] + 2;
                    break;
                    // dp[i] = max(dp[i], tmp);
                }
            }
        }

        return dp[0] > 0 ? dp[0] : 1;
    }
};
