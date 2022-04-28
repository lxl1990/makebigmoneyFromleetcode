/*
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j]

*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int pre = 0;
            for (int j = 0; j <= i; j++) {
                int tmp = dp[j];
                if (j > 0) dp[j] = min(dp[j], pre);
                if (j == i) dp[j] = pre;
                dp[j] += triangle[i][j];    
                pre = tmp;
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
