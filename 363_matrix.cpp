class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ans = 1 << 31;
        cout << ans << endl;
        for (int bottom = 1; bottom <= m; bottom++) {
            for (int up = bottom; up <= m; up++) {
                set<int> s;
                s.insert(0);
                for (int right = 1; right <= n; right++) {
                    int sumRight = sum[up][right] - sum[bottom - 1][right];
                    auto itr = s.lower_bound(sumRight - k);
                    if (itr != s.end()) ans = max(ans, sumRight - *itr);
                    s.insert(sumRight);
                }
            }
        }
        return ans;
    }
};
