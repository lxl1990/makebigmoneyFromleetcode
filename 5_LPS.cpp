/*
    Manacher 
*/
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string newStr = "#";
        for (char c : s) {
            newStr += c;
            newStr += '#';
        }

        std::vector<int> armLens;
        int rightIndex = -1, center = -1;
        int start = 0, end = -1;
        // std::cout << "newStr: " << newStr << std::endl;
        for (int i = 0; i < newStr.size(); i++) {
            // std::cout << "i: " << i << std::endl;
            int armLen = 0;
            if (i > rightIndex) {
                armLen = expandFromCenter(newStr, i, i);
            } else {
                // std::cout << "rightIndex: " << rightIndex << ", center: " << center << std::endl;
                int leftMirror = 2 * center - i;
                int minArm = std::min(armLens[leftMirror], rightIndex - i);
                armLen = expandFromCenter(newStr, i - minArm, i + minArm);
            }
            
            if (i + armLen > rightIndex) {
                rightIndex = i + armLen;
                center = i;
            }
            armLens.emplace_back(armLen);
            if (2 * armLen + 1 > end - start) {
                start = i - armLen;
                end = i + armLen;
            }
            // std::cout << "armLen: " << armLen << std::endl;
        }

        std::string ret = "";
        for (int i = start; i <= end; i++) {
            if (newStr[i] == '#') continue;
            ret += newStr[i];
        }
        return ret;
    }
    int expandFromCenter(std::string& str, int l, int r) {
        while (l >= 0 && r < str.size() && str[r] == str[l]) {
            l--;
            r++;
        }
        return (r - l - 2) / 2;
    }
};
