/*
    deterministic finite automaton
*/
class AutoMaton {
public:
    int sign = 1;
    long long nums = 0;
    string state = "start";

    unordered_map<string, vector<string>> stateChangeTable = {
        {"start", {"start", "sign", "number", "end"}},
        {"sign", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int charType(char c) {
        if (c == ' ') {
            return 0;
        } else if (c == '+' || c == '-') {
            return 1;
        } else if (c >= '0' && c <='9') {
            return 2;
        }
        return 3;
    }
    void getChar(char c) {
        int c_type = charType(c);
        state = stateChangeTable[state][c_type];
        // cout << "c: " << c << ", c_type: " << c_type << ", state: " << state << endl;
        if (state == "number") {
            nums = nums * 10 + (c - '0');
        } else if (state == "sign") {
            sign = c == '-' ? -1 : 1;
        }
    }
};
class Solution {
private:
    int MaxV = (int) (long (1 << 31) - 1);
    int MinV = 1 << 31;
public:
    int myAtoi(string s) {
        AutoMaton am;
        for (char c: s) {
            am.getChar(c);
            if (am.state == "end") {
                break;
            } else if (am.state == "number" && (am.nums * am.sign >= MaxV || am.nums * am.sign <= MinV)) {
                break;
            }
        }
        return am.sign == 1 ? min((long long)MaxV, am.nums) : max(-1 * am.nums, (long long) MinV);
    }
};
