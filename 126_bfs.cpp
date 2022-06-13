/*
    Similar to Q 127, return all the shortest path not the length;
*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet = {wordList.begin(), wordList.end()};
        vector<vector<string>> ret;
        if (!wordSet.count(endWord)) return ret;
        queue<string> queue;
        queue.push(beginWord);
        int step = 0;
        bool isBreak = false; //once reach endWord, exit after this layer.
        unordered_map<string, vector<string>> fromWord; //for brack trace all the paths
        unordered_map<string, int> wordSteps;
        wordSteps.emplace(beginWord, step);
        wordSet.erase(beginWord);
        while (!queue.empty()) {
            step++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                string curString = queue.front();
                queue.pop();
                string nextString(curString);
                for (int j = 0; j < nextString.size(); j++) {
                    const char origin = nextString[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == origin) continue;
                        nextString[j] = c;
                        //curString has been reached at this layer
                        if (wordSteps[nextString] == step) {
                            fromWord[nextString].emplace_back(curString);
                        }
                        //curString has been reached before
                        if (!wordSet.count(nextString)) continue;
                        wordSteps[nextString] = step;
                        fromWord[nextString].emplace_back(curString);
                        wordSet.erase(nextString);
                        if (nextString == endWord) isBreak = true;
                        queue.push(nextString);
                        
                    }
                    nextString[j] = origin;
                }
            }
            if (isBreak) break;
        }
        if (isBreak) {
            vector<string> path = {endWord};
            backTrack(fromWord, path, endWord, ret);
        }
        return ret;
    }

    void backTrack(unordered_map<string, vector<string>>& fromWord, vector<string>& path, string word, vector<vector<string>>& ret) {
        if (!fromWord.count(word)) {
            ret.emplace_back(path.rbegin(), path.rend());
            return;
        }
        for (string next: fromWord[word]) {
            path.emplace_back(next);
            backTrack(fromWord, path, next, ret);
            path.pop_back();
        }
        return;
    }
};
