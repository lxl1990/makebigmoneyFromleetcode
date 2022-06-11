class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int n = s.size(), i = 0, num = 0;
        while (i < n) {
            // cout << "i:" << i << ", preSign: " << preSign << endl;
            while (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + int(s[i] - '0');
                i++;
            }
	        if (s[i] != ' ' || i == n - 1) { 
                if (preSign == '+') {
                    stk.push_back(num);
                } else if (preSign == '-') {
                    stk.push_back(-num);
                } else if (preSign == '*') {
                    stk.back() *= num;
                } else if (preSign == '/') {
                    stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
                
            }
            i++;
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
