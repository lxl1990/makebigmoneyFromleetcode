/*
类似17.24最大子矩阵问题；划定上下限，将二维问题转为一维；前向累积和，计算
*/
// class Solution {
// public:
//     int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//         int m = matrix.size();
//         if (m == 0) return 0;
//         int n = matrix[0].size();
//         if (n == 0) return 0;
//         int maxSum = 1 << 31;
//         for (int i = 0; i < m; i++) {
//             vector<int> b(n, 0);
//             for (int j = i; j < m; j++) {
//                 vector<int> preSum(n+1, 0);
//                 for (int cur = 0; cur < n; cur++) {
//                     b[cur] += matrix[j][cur];
//                     preSum[cur + 1] += preSum[cur] + b[cur];
//                     for (int pre = 0; pre <= cur; pre++) {
//                         int tmp = preSum[cur + 1] - preSum[pre];
//                         if (tmp <= k && tmp > maxSum) {
//                             maxSum = tmp;
//                         }
//                     }
//                 }
//             }
//         }
//         return maxSum;
//     }
// };

/*二分优化*/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int maxSum = 1 << 31;
        vector<int> sumPre(n, 0);
        for (int i = 0; i <  m; i++) {
            fill(sumPre.begin(), sumPre.end(), 0);
            for (int j = i; j < m; j++) {
                set<int> set;
                int curSum = 0;
                set.insert(curSum);
                // cout << "i: " << i << ", j: " << j << endl;
                // cout << "sumPre: " << endl;
                for (int cur = 0; cur < n; cur++) {
                    sumPre[cur] += matrix[j][cur];
                    // cout <<  "," << sumPre[cur];
                    curSum += sumPre[cur];
                    auto it = set.lower_bound(curSum - k);
                    if (it != set.end()) {
                        maxSum = max(maxSum, curSum - *it);
                    }
                    set.insert(curSum);
                }
                // cout << endl;
            }
        }
        return maxSum;
    }
};


// class Solution {
// public:
//     int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
//         int m = matrix.size();
//         if (m == 0) return 0;
//         int n = matrix[0].size();
//         if (n == 0) return 0;
//         int maxSum = 1 << 31;
//         bool isTrans = m > n;
//         vector<int> sumPre((isTrans ? m : n), 0);
//         for (int i = 0; i <  (isTrans ? n : m); i++) {
//             fill(sumPre.begin(), sumPre.end(), 0);
//             for (int j = i; j < (isTrans ? n : m); j++) {
//                 set<int> set;
//                 int curSum = 0;
//                 set.insert(curSum);
//                 // cout << "i: " << i << ", j: " << j << endl;
//                 // cout << "sumPre: " << endl;
//                 for (int cur = 0; cur < (isTrans ? m : n); cur++) {
//                     sumPre[cur] += (isTrans ? matrix[cur][j] : matrix[j][cur]);
//                     // cout <<  "," << sumPre[cur];
//                     curSum += sumPre[cur];
//                     auto it = set.lower_bound(curSum - k);
//                     if (it != set.end()) {
//                         maxSum = max(maxSum, curSum - *it);
//                     }
//                     set.insert(curSum);
//                 }
//                 // cout << endl;
//             }
//         }
//         return maxSum;
//     }
// };
