///*
//    主要分为两种回溯
//    backTraceFirst为"()“括号维度回溯，为第一优先级
//    backTraceSecond为 “* /“ 乘除维度回溯，为第二优先级
//    
//*/
//class Solution {
//private:
//    int backTraceFirst(list<int>& numStk, stack<char>& signStk) {
//        int ret = 0;
//        int num = numStk.back();
//        numStk.pop_back();
//        while (!signStk.empty() && !numStk.empty() && signStk.top() != '(') {
//            char sign = signStk.top(); signStk.pop();
//            if (sign == '+') {
//                ret += num;
//            } else if (sign == '-') {
//                ret -= num;
//            }
//            num = numStk.back();
//            numStk.pop_back();
//        }
//        if (!signStk.empty() && signStk.top() == '(') signStk.pop();
//        return ret + num;
//    }
//    void backTraceSecond(list<int>& numStk, stack<char>& signStk) {
//        if (signStk.empty()) return;
//        if (signStk.top() == '*') {
//            int num = numStk.back(); numStk.pop_back();
//            signStk.pop();
//            numStk.back() *= num;
//        } else if (signStk.top() == '/') {
//            int num = numStk.back(); numStk.pop_back();
//            signStk.pop();
//            numStk.back() /= num;
//        }
//    }
//public:
//    int calculate(string s) {
//        stack<char> signStk;
//        list<int> numStk;
//        int num = 0, i = 0, n = s.size();
//        while (i < n) {
//            if (s[i] == '(') {
//                signStk.push(s[i]);
//                i++;
//            } else if (s[i] == ')') {
//                numStk.push_back(backTraceFirst(numStk, signStk));
//                backTraceSecond(numStk, signStk);
//                i++;
//            } else if (s[i] >= '0' && s[i] <= '9') {
//                while (i < n && s[i] >= '0' && s[i] <= '9') {
//                    num = num * 10 + int(s[i] - '0');
//                    i++;
//                }
//                numStk.push_back(num);
//                backTraceSecond(numStk, signStk);
//                num = 0;
//            } else {
//                if (s[i] != ' ') signStk.push(s[i]);
//                i++;
//            }
//        }
//        return backTraceFirst(numStk, signStk);
//    }
//};

/*
  Reverse Polish Notation
*/
class Solution {
private:
    unordered_map<char, int> opMap = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
    };
    int optPriority(char c) {
        if (!opMap.count(c)) return 0;
        return opMap[c];
    }

    void reversePolishNotation(string& s, vector<string>& ret) {
        int i = 0, n = s.size();
        stack<char> stk;
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                string tmp = "";
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    tmp += s[i];
                    i++;
                }
                ret.push_back(tmp);
            } else if (opMap.count(s[i])) {
                while (!stk.empty() && optPriority(stk.top())>= optPriority(s[i])) {
                    string tmp = "";
                    tmp += stk.top();
                    ret.push_back(tmp);
                    stk.pop();
                }
                stk.push(s[i]);
                i++;
            } else if (s[i] == '(') {
                stk.push(s[i]);
                i++; 
            } else if (s[i] == ')') {
                while (!stk.empty() && stk.top() != '(') {
                    string tmp = "";
                    tmp += stk.top();
                    ret.push_back(tmp);
                    stk.pop();
                }
                if (!stk.empty()) stk.pop();
                i++;
            } else {
                i++;
            }
        }
        while (!stk.empty()) {
            string tmp = "";
            tmp += stk.top();
            ret.push_back(tmp);
            stk.pop();
        }
    }
    
    int computeReversePolishNotation(vector<string>& ll) {
        stack<int> stk;
        for (int i = 0; i < ll.size(); i++) {
            if (opMap.count(ll[i][0])) {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                if (ll[i] == "*") {
                    stk.push(a * b);
                } else if (ll[i] == "/") {
                    stk.push(b / a);
                } else if (ll[i] == "+") {
                    stk.push(a + b);
                } else if (ll[i] == "-") {
                    stk.push(b - a);
                }
            } else {
                int num = 0;
                for (int k = 0; k < ll[i].size(); k++) {
                    num = num * 10 + int(ll[i][k] - '0');
                }
                stk.push(num);
            }
        }
        return stk.top();
    }
public:
    int calculate(string s) {
        vector<string> reversePolish;
        reversePolishNotation(s, reversePolish);
        // for (int i = 0; i < reversePolish.size(); i++) {
        //     cout << reversePolish[i] << endl;
        // }     
        return computeReversePolishNotation(reversePolish);
    }

};

"14/3*2"
"3+2*2"
"1-1+1"
"2*(5+5*2)/3+(6/2+8)"
2552*+*3/62/8++

