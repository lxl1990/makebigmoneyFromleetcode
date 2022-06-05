// /*
//     Tries  sacrifices space for time
// */
// class Solution {
// private:
//     struct TrieNode {
//         int wordEndIndex;
//         int nextNode[26];
//         TrieNode(): wordEndIndex(-1) {
//             memset(nextNode, 0, sizeof(nextNode));
//         }
//     };
//     std::vector<TrieNode> trees;
// public:
//     std::vector<vector<int>> palindromePairs(std::vector<string>& words) {
//         trees.emplace_back(TrieNode());
//         int n = words.size();

//         for (int i = 0; i < n; i++) {
//             insert(words[i], i);
//         }

//         std::vector<vector<int>> ret;
//         for (int i = 0; i < n; i++) {
//             int m = words[i].size();
//             for (int j = 0; j <= m; j++) {
//                 if (isPalindrome(words[i], j, m - 1)) {
//                     int rightIndex = findWord(words[i], 0, j - 1);
//                     if (rightIndex != -1 && rightIndex != i) {
//                         // ret.emplace_back(vector<int>{i, rightIndex});
//                         ret.push_back({i, rightIndex});
//                     }
//                 }

//                 if (j && isPalindrome(words[i], 0, j - 1)) {
//                     int leftIndex = findWord(words[i], j, m - 1);
//                     if (leftIndex != -1 && leftIndex != i) {
//                         ret.push_back({leftIndex, i});
//                     }
//                 }
//             }
//         }
//         return ret;
//     }

//     int findWord(std::string& word, int left, int right) {
//         // std::cout <<"word: " << word << std::endl;
//         int curIndex = 0;
//         for (int i = right; i >= left; i--) {
//             int id = word[i] - 'a';
//             // std::cout << "id: " << id << ", word[i]: " << word[i] << std::endl;
//             if (!trees[curIndex].nextNode[id]) return -1;
//             curIndex = trees[curIndex].nextNode[id];
//         }
//         return trees[curIndex].wordEndIndex;
//     }

//     bool isPalindrome(std::string& word, int left, int right) {
//         while (left < right) {
//             if (word[left] != word[right]) break;
//             left++;
//             right--;
//         }
//         return (left >= right) ? true : false;
//     }

//     void insert(std::string& word, int index) {
//         int curIndex = 0;
//         for (int i = 0; i < word.size(); i++) {
//             int id = word[i] - 'a';
//             if (!trees[curIndex].nextNode[id]) {
//                 trees.emplace_back(TrieNode());
//                 trees[curIndex].nextNode[id] = trees.size() - 1;
//             }
//             curIndex = trees[curIndex].nextNode[id];
//         }
//         trees[curIndex].wordEndIndex = index;
//     }
// };



// /*
//     Hash  sacrifices space for time
// */
// class Solution {
// private:
//     std::unordered_map<std::string, int> postfixs;

// public:
//     std::vector<vector<int>> palindromePairs(std::vector<string>& words) {
//         int n = words.size();

//         for (int i = 0; i < n; i++) {
//             std::string str = words[i];
//             reverse(str.begin(), str.end());
//             postfixs[str] = i;
//         }

//         std::vector<vector<int>> ret;
//         for (int i = 0; i < n; i++) {
//             int m = words[i].size();
//             if (!m) continue;
//             for (int j = 0; j <= m; j++) {
//                 if (isPalindrome(words[i], j, m - 1)) {
//                     int rightIndex = findWord(words[i], 0, j - 1);
//                     if (rightIndex != -1 && rightIndex != i) {
//                         // ret.emplace_back(vector<int>{i, rightIndex});
//                         ret.push_back({i, rightIndex});
//                     }
//                 }

//                 if (j && isPalindrome(words[i], 0, j - 1)) {
//                     int leftIndex = findWord(words[i], j, m - 1);
//                     if (leftIndex != -1 && leftIndex != i) {
//                         ret.push_back({leftIndex, i});
//                     }
//                 }
//             }
//         }
//         return ret;
//     }

//     int findWord(std::string& word, int left, int right) {
//         // std::cout <<"word: " << word << std::endl;
//         std::string str = "";
//         if (right >= left) {
//             str = word.substr(left, right - left + 1);
//         }
//         auto iter = postfixs.find(str);
//         return iter == postfixs.end() ? -1 : iter->second;
//     }

//     bool isPalindrome(std::string& word, int left, int right) {
//         while (left < right) {
//             if (word[left] != word[right]) break;
//             left++;
//             right--;
//         }
//         return (left >= right) ? true : false;
//     }
// };


/*
    Manacher + Trie
*/
class Solution {
private:
    struct TrieNode {
        struct Node {
            int wordEndIndex;
            int nextNode[26];
            Node(): wordEndIndex(-1) {
                memset(nextNode, 0, sizeof(nextNode));
            }
        };
        vector<Node> trees;
        TrieNode() {trees.emplace_back(Node());}
        void insert(std::string& word, int index) {
            // std::cout << "insert word " << word << std::endl; 
            int curIndex = 0;
            for (char c : word) {
                int id = c - 'a';
                if (!trees[curIndex].nextNode[id]) {
                    trees.emplace_back(Node());
                    trees[curIndex].nextNode[id] = trees.size() - 1;
                }
                curIndex = trees[curIndex].nextNode[id];
                // std::cout << "curIndex " << curIndex << std::endl;
            }
            trees[curIndex].wordEndIndex = index;
        }

        vector<int> find(std::string& word) {
            int m = word.size();
            vector<int> ret(m + 1, -1);
            int curIndex = 0;
            ret[0] = trees[curIndex].wordEndIndex;
            for (int i = 0; i < m; i++) {
                int id = word[i] - 'a';
                if (!trees[curIndex].nextNode[id]) break;
                curIndex = trees[curIndex].nextNode[id];
                ret[i + 1] = trees[curIndex].wordEndIndex;
            }
            return ret;
        }
    };
    
public:
    std::vector<vector<int>> palindromePairs(std::vector<string>& words) {
        int n = words.size();
        TrieNode trie1, trie2; 
        for (int i = 0; i < n; i++) {
            std::string tmp = words[i];
            trie1.insert(tmp, i);
            reverse(tmp.begin(), tmp.end());
            trie2.insert(tmp, i);
        }
        std::vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            // std::cout << "i: " << i << std::endl;
            int m = words[i].size();
            vector<pair<int, int>> palindrome = manacher(words[i]);
            // std::cout << " manacher process over" << std::endl;
            vector<int> prefixs = trie2.find(words[i]);
            reverse(words[i].begin(), words[i].end());
            vector<int> postfixs = trie1.find(words[i]);
            // for (int i = 0; i <= m; i++) {
            //     std::cout << "i: " << i << ", prefixs[i]: " << prefixs[i] << ", postfixs[i]: " << postfixs[i] << std::endl;
            // }
            // std::cout << " data process over" << std::endl;
            for (int j = 0; j < m; j++) {
                if (palindrome[j].second == 1) {
                    int rightId = prefixs[j];
                    if (rightId != -1 && rightId != i) {
                        ret.push_back({i, rightId});
                    }
                }
                if (palindrome[j].first) {
                    int leftId = postfixs[m - 1 - j];
                    if (leftId != -1 && leftId != i) {
                        ret.push_back({leftId, i});
                    }
                }
            }
            if (prefixs[m] != -1 && prefixs[m] != i) {
                ret.push_back({i, prefixs[m]});
            }
        }
        return ret;
    }

    vector<pair<int, int>> manacher(std::string& word) {
        std::string newWord = "";
        newWord = "#";
        for (char c : word) {
            newWord += c;
            newWord += '#';
        }
        // std::cout << "newWord: " << newWord << std::endl;
        int m = word.size();

        vector<int> armLens(2 * m);
        vector<pair<int, int>> ret(m);
        int rightIndex = -1, center = -1;
        for (int i = 1; i < 2 * m; i++) {
            // std::cout << "i: " << i << ", rightIndex: " << rightIndex << ", center: " << center;
            int armLen = 0;
            if (i > rightIndex) {
                armLen = expandFromCenter(newWord, i, i);
            } else {
                int mirror = 2 * center - i;
                armLen = std::min(armLens[mirror], rightIndex - i);
                armLen = expandFromCenter(newWord, i - armLen, i + armLen);
            }
            // std::cout << ", armLen: " << armLen << std::endl;
            if (i + armLen > rightIndex) {
                rightIndex = i + armLen;
                center = i;
            }

            if (i - armLen == 0) {
                ret[(i + armLen) / 2 - 1].first = 1;
            }

            if (i + armLen == 2 * m) {
                ret[(i - armLen) / 2].second = 1;
            }
        }

        return ret;
    }

    int expandFromCenter(std::string& str, int left, int right) {
        while (left >= 0 && right < str.size() && str[left] == str[right]) {
            left--;
            right++;
        }
        return (right - left - 2) / 2;
    }
};


