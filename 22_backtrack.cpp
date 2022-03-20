// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> result;
//         string str = "";
//         backTack(result, str, 0, 0, n);
//         return result;
//     }
//     void backTack(vector<string>& result, string& str, int left, int right, int target) {
//         if (right == target) {
//             result.emplace_back(str);
//             return;
//         }
//         //先添左括号
//         if (left < target) {
//             str.push_back('(');
//             backTack(result, str, left + 1, right, target);
//             str.pop_back();
//         }
//         //再添加右括号
//         if (left > right) {
//             str.push_back(')');
//             backTack(result, str, left, right + 1, target);
//             str.pop_back();
//         }
//     }
// };

class Solution {
private:
    shared_ptr<vector<string>> cache[100] = {nullptr};
public:
    vector<string> generateParenthesis(int n) {
        backTrack(n);
        return *cache[n];
    }
    void backTrack(int n) {
        if (cache[n] != nullptr) {
            return;
        }
        if (n == 0) {
            cache[n] = shared_ptr<vector<string>>(new vector<string>{""});
            return;
        }
        auto result = shared_ptr<vector<string>>(new vector<string>());
        for (int i = 0; i < n; i++) {
            backTrack(i);
            backTrack(n - i - 1);
            for (string left: *cache[i]) {
                for (string right: *cache[n - i -1]) {
                    result->push_back("(" + left  + ")" + right);
                }
            }
        }
        cache[n] = result;
    }
};
