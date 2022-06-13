/*
    Divide the nums into three parts, some are divisible by 3, and some are divisible by 3 with a remainder of 1, and some are divisible by 3 with a remainder of 2.
    Then sort the second and third part by descending order;
*/
// class Solution {
// public:
//     int maxSumDivThree(vector<int>& nums) {
//         vector<int> divid1, divid2;
//         int ret = 0;
//         for (int num: nums) {
//             if (num % 3 == 0) {
//                 ret += num;
//             } else if (num % 3 == 1) {
//                 divid1.emplace_back(num);
//             } else {
//                 divid2.emplace_back(num);
//             }
//         }
//         return ret + mergeTwoPart(divid1, divid2, 0, 0);
//     }

//     int mergeTwoPart(vector<int>& divid1, vector<int>& divid2, int begin1, int begin2) {
        
//         int ret = 0;
//         if (divid1.size() - begin1 == divid2.size() - begin2) {
//             for (int i = begin1; i < divid1.size(); i++) {
//                 ret += divid1[i];
//             }
//             for (int i = begin2; i < divid2.size(); i++) {
//                 ret += divid2[i];
//             }
//             return ret;
//         }
//         sort(divid1.rbegin(), divid1.rend());
//         sort(divid2.rbegin(), divid2.rend());
//         int m = divid1.size();
//         int n = divid2.size();
//         if (divid1.size() == 0) {
//             for (int i = 0; i < n - (n % 3); i++) {
//                 ret += divid2[i];
//             }
//             return ret;
//         }
//         if (divid2.size() == 0) {
//             for (int i = 0; i < m - (m % 3); i++) {
//                 ret += divid1[i];
//             }
//             return ret;
//         }
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

//         for (int i = m - 1; i >= 0; i--) {
//             for (int j = n - 1; j >= 0; j--) {
//                 dp[i][j] = divid1[i] + divid2[j] + dp[i+1][j+1];
//                 if (i + 3 <= m) dp[i][j] = max(dp[i][j], divid1[i] + divid1[i + 1] + divid1[i + 2] + dp[i + 3][j]);
//                 if (j + 3 <= n) dp[i][j] = max(dp[i][j], divid2[j] + divid2[j + 1] + divid2[j + 2] + dp[i][j + 3]);
//             }
//         }
//         return dp[0][0];
//     }
// };



class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> remaind(3, 0);
        for (int num : nums) {
            int a = num + remaind[0];
            int b = num + remaind[1];
            int c = num + remaind[2];
            remaind[a%3] = max(remaind[a%3], a);
            remaind[b%3] = max(remaind[b%3], b);
            remaind[c%3] = max(remaind[c%3], c);
        }
        return remaind[0];
    }
};
