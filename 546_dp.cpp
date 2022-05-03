class Solution {
private:
    vector<vector<vector<int>>> dp;
    int calcLargest(vector<int>& boxes, int left, int right, int k) {
        if (left > right) return 0;
        if (dp[left][right][k]) return dp[left][right][k];
        int r = right, kk = k;
        while (r >= left && boxes[r] == boxes[right]) {
            r--;
            kk++;
        }
        dp[left][right][k] = calcLargest(boxes, left, r, 0) + kk * kk;
        for (int i = left; i < r; i++) {
            if (boxes[i] == boxes[r + 1]) {
                dp[left][right][k] = max(dp[left][right][k], calcLargest(boxes, left, i, kk) + calcLargest(boxes, i + 1, r, 0));
            }
        }
        return dp[left][right][k];
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 0)));
        return calcLargest(boxes, 0, n - 1, 0);
    }
};
