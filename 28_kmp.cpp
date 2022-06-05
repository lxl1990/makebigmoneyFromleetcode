class KMP {
public:
    vector<int> next;
    KMP(std::string& pat, int m) {
        next = vector<int>(m, 0);
        int j = 0;
        for (int i = 1; i < m; i++) {
            while (j > 0 && pat[i] != pat[j]) {
                j = next[j - 1];
            }
            if (pat[i] == pat[j]) {
                j++;
            }
            next[i] = j;
        }
    }
};
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        if (m == 0) return 0;
        KMP* kmpAction = new KMP(needle, m);
        vector<int>& next = kmpAction->next;
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) j++;

            if (j == m) return i - m + 1;
        }
        return  -1;
    }
};
