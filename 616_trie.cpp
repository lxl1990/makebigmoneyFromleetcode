/*
    Trie
*/
class Solution {
private:
    struct TrieNode {
        char val;
        bool flag;
        unordered_map<char, TrieNode*> nextNode;
        TrieNode(): flag(false), val(' ') {}
    };
    TrieNode* root;
public:
    string addBoldTag(string s, vector<string>& words) {
        root = new TrieNode();
        addSearchWords(words);
        // std::cout << "add words over" << std::endl;
        list<pair<int, int>> segments;
        int left = 0, right = -1;
        for (int i = 0; i < s.size(); i++) {
            int rightIndex = searchWord(s, i);
            if (rightIndex == -1) continue;
            if (i > right + 1) {
                if (right >= left) segments.emplace_back(make_pair(left, right));
                left = i;
                right = rightIndex;
            } else {
                right = std::max(right, rightIndex);
            }
            // std::cout << "i: " << i << ", left: " << left << ", right: " << right << std::endl; 
        }
        if (right >= left) {
            segments.emplace_back(make_pair(left, right));
        }

        // std::cout << "segments over" << std::endl;
        std::string ret = "";
        for (int i = 0; i < s.size(); i++) {
            if (!segments.empty() && segments.front().first == i) {
                ret += "<b>";
            }
            ret += s[i];
            if (!segments.empty() && segments.front().second == i) {
                ret += "</b>";
                segments.pop_front();
            }
        }
        return ret;
    }

    int searchWord(std::string& str, int begin) {
        int ret = -1;
        auto node = root;
        // std::cout << "search word " << str << ", begin: " << begin << std::endl;
        for (int i = begin; i < str.size(); i++) {
            // std::cout << "i: " << i << ", " << str[i] << std::endl;
            if (!node->nextNode.count(str[i])) break;
            node = node->nextNode[str[i]];
            // std::cout << "node " << node->val << ", " << node->flag << std::endl;
            if (node->flag) ret = i;
        }
        return ret;
    }

    void addSearchWords(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            // std::cout << "add word " << words[i] << std::endl;
            addWord(words[i]);
        }
    }

    void addWord(std::string& word) {
        auto node = root;
        for (int i = 0; i < word.size(); i++) {
            // std::cout << "i: " << i << ", node->val: " << node->val << std::endl;
            if (!node->nextNode.count(word[i])) {
                node->nextNode[word[i]] = new TrieNode();
            }
            node = node->nextNode[word[i]];
            node->val = word[i];
        }
        node->flag = true;
        // std::cout << "end node->val: " << node->val << std::endl;
    }
};
