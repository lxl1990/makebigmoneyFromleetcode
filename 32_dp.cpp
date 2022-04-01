// /*
//     参考判断是否为有效括号的方法
//     借助栈，stack, 压入 "(" 的索引i，遇到 ")"的索引j，使用栈内的索引计算长度
// */
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.size();
//         if (n <= 1) return 0;
//         stack<int> stk;
//         stk.push(-1);
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             if (s[i] == '(') {
//                 stk.push(i);
//             } else {
//                 stk.pop();
//                 if (stk.empty()) {
//                     stk.push(i);
//                 } else {
//                     ans = max(ans, i - stk.top());
//                 }
//             }
//         }
//         return ans;
//     }
// };


/*优化空间，不借助栈*/
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.size();
//         if (n <= 1) return 0;
//         vector<int> dp(n, 0);
//         int ans = 0;
//         for (int i = 1; i < n; i++) {
//             if (s[i] == ')') {
//                 if (s[i - 1] == '(') {
//                     dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
//                 } else if (dp[i - 1] > 0 && i > dp[i - 1] && s[i - dp[i - 1] - 1] == '(') {
//                     dp[i] = 2 + dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0);
//                 }
//             }
//             ans = max(ans, dp[i]);
//         }
//         return ans;
//     }
// };



/*再次优化空间*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                ans = max(ans, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = 0, right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                ans = max(ans, 2 * right);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return ans;
    }
};

