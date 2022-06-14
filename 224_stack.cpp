class Solution {
private:
    int ret = 0;
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> signStk;
        int ret = 0, i = 0, preSign = 1;
        signStk.push(preSign);
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                preSign = signStk.top();
                i++;
            } else if (s[i] == '-') {
                preSign = -signStk.top();
                i++;
            } else if (s[i] == '(') {
                signStk.push(preSign);
                i++;
            } else if (s[i] == ')') {
                signStk.pop();
                i++;
            } else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += preSign * num;
            }
        }
        return ret;
    }
    
};
