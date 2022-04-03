// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans;
//         ans.emplace_back(0);
//         if (n == 0) return ans;
//         int vecSize = 1;
//         while (vecSize <= n) {
//             for (int i = 0; i < vecSize && i <= n - vecSize; i++) {
//                 ans.emplace_back(ans[i] + 1);
//             }
//             vecSize = ans.size();
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n + 1, 0);
//         int highbit = 0;
//         for (int i = 1; i <= n; i++) {
//             if ((i & (i - 1)) == 0) {
//                 highbit = i;
//             }
//             ans[i] = ans[i - highbit] + 1;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n + 1, 0);
//         for (int i = 1; i <= n; i++) {
//             ans[i] = ans[i >> 1] + (i & 1);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};
