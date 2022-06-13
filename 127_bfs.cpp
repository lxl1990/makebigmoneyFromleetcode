// /*
//     The shortest sequence can be get by bfs
    
//     To reduce the complexity of space, we can use bidirectional bfs. Two queues are used, one for beginWord and one for endWord to search. But the complexity is under control by wordList.

//     The most important step is building a graph to link the node. Each node indicates a word of wordList or the beginWord. To link the node "hit" and the node "hot", we need a virtual node "h*t". The path in example 1 can be represented as follows
//     hit->h*t->hot->*ot->dot->do*->dog->*og->cog
// */
// class Solution {
// private:
//     unordered_map<string, int> wordId;
//     vector<vector<int>> edges;
//     int num = 0;
//     void addWordID(string word) {
//         if (!wordId.count(word)) {
//             wordId.emplace(word, num);
//             edges.emplace_back(vector<int>());
//             num++;
//         }
//     }
//     void addEdges(string word) {
//         addWordID(word);
//         int curId = wordId[word];
//         for (char & it: word) {
//             char tmp = it;
//             it = '*';
//             addWordID(word);
//             int nextId = wordId[word];
//             edges[curId].push_back(nextId);
//             edges[nextId].push_back(curId);
//             it = tmp;
//         }
//     }
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         for (int i = 0; i < wordList.size(); i++) {
//             addEdges(wordList[i]);
//         }
//         addEdges(beginWord);
//         if (!wordId.count(endWord)) return 0;
//         int endId = wordId[endWord];
//         int beginId = wordId[beginWord];
//         vector<int> visited(num, 0);
//         visited[beginId] = 1;
//         int dis = 0;
//         queue<int> queue;
//         queue.push(beginId);
//         while(!queue.empty()) {
//             dis++;
//             int curSize = queue.size();
//             for (int i = 0; i < curSize; i++) {
//                 int cur = queue.front(); queue.pop();
//                 for (int next: edges[cur]) {
//                     if (next == endId) return dis/2 + 1;
//                     if (visited[next] == 1) continue;
//                     queue.push(next);
//                     visited[next] = 1;
//                 }
//             }
//         }
//         return 0;
//     }
// };


/*
    bit the solution 1
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet = {wordList.begin(), wordList.end()};
        if (!wordSet.count(endWord)) return 0;
        queue<string> queue;
        queue.push(beginWord);
        int ret = 0;
        while (!queue.empty()) {
            int size = queue.size();
            ret++;
            for (int i = 0; i < size; i++) {
                string curString = queue.front();
                queue.pop();
                if (curString == endWord) return ret;
                for (int j = 0; j < curString.size(); j++) {
                    char & curChar = curString[j];
                    char tmp = curChar;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == tmp) continue;
                        curChar = c;
                        if (!wordSet.count(curString)) continue;
                        wordSet.erase(curString);
                        queue.push(curString);
                    }
                    curChar = tmp;
                }
            }
        }
        return 0;
    }
};
