/*
dp[i][j] 表示以 i, j 结尾的数组最大长度
k = index(arr[j] - arrA[i]), 且 k < i
dp[i][j] = dp[k][i] + 1
*/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            map.emplace(arr[i], i);
        }
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 1; i < n; i++) {
            for (int j = i + 1 ; j < n; j++) {
                if (arr[j] - arr[i] < arr[i] && map.count(arr[j] - arr[i])) {
                    int k = map[arr[j] - arr[i]];
                    dp[i][j] = dp[k][i] + 1;
                    ans = max(ans, dp[i][j] + 2);
                }
            }
        }
        return ans;
    }
};
