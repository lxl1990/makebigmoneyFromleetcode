/*
 类似柱子的最大矩形87
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<int> height(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            //更新height
            for (int j = 0; j < n; j++) {
                height[j] = matrix[i][j] == '0' ? 0 : height[j] + 1;
            }
            //使用单调栈，更新每个位置的左右边界
            vector<int> left(n, 0);
            vector<int> right(n, n);
            stack<int> stk;
            for (int j = 0; j < n; j++) {
                while (!stk.empty() && height[stk.top()] >= height[j]) {
                    right[stk.top()] = j;
                    stk.pop();
                }
                left[j] = stk.empty() ? -1 : stk.top();
                stk.push(j);
            }
            for (int j = 0; j < n; j++) {
                ans = max(ans, height[j] * (right[j] - left[j] - 1));
            }
        }
        return ans;
    }
};
