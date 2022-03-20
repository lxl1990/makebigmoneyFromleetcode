class Solution {
    public:
        bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
            //n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
            vector<vector<int>> graph(n + 1);
            for (auto& dislike : dislikes) {
                graph[dislike[0]].push_back(dislike[1]);
                graph[dislike[1]].push_back(dislike[0]);
            }
            vector<int> color(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                if (color[i] != 0) {
                    continue;
                }
                color[i] = 1;
                queue<int> que;
                que.push(i);
                while (!que.empty()) {
                    int v = que.front();
                    que.pop();
                    for (int next : graph[v]) {
                        if (color[next] * color[v] == 1) return false;
                        if (color[next] == 0) que.push(next);
                        color[next] = -1 * color[v];
                    }
                }
            }
            return true;
        }
};
