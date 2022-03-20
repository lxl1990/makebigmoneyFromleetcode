class Solution {
    public:
        int minimumSemesters(int n, vector<vector<int>>& relations) {
            //返回最大深度
            int ret = -1;
            vector<vector<int>> graph(n + 1);
            for (auto& relation : relations) {
                graph[relation[0]].push_back(relation[1]);
            }
            vector<int> depths(n + 1, -1);
            for (int i = 1; i <= n; i++) {
                dfs(graph, depths, i);
                if (depths[i] < 0) return -1;
                ret = max(ret, depths[i]);
            }
            return ret;
        }
        void dfs(vector<vector<int>>& graph, vector<int>& depths, int cur) {
            if (depths[cur] > 0) {
                return;
            }
            if (depths[cur] == 0) {
                depths[cur] = -1;
                return;
            }
            depths[cur] = 0;
            for (int v : graph[cur]) {
                dfs(graph, depths, v);
                if (depths[v] < 0) {
                    depths[cur] = -1;
                    return;
                }
                depths[cur] = max(depths[cur], depths[v]);
            }
            depths[cur]++;
        }
};
