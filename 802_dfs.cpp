// class Solution {
// public:
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         //dfs
//         int n = graph.size();
//         vector<int> flag(n, 0);
//         for (int i = 0; i < n; i++) {
//             dfs(graph, flag, i);
//         }
//         vector<int> ret;
//         for (int i = 0; i < n; i++) {
//             if (flag[i] == 1) continue;
//             ret.push_back(i);
//         }
//         return ret;
//     }
//     //flag == 1 历史访问过 或者 存在环， 2 无环
//     void dfs(vector<vector<int>>& graph, vector<int>& flag, int i) {
//         if (flag[i] > 0) return;
//         flag[i] = 1;
//         for (int next: graph[i]) {
//             dfs(graph, flag, next);
//             if (flag[next] == 1) {
//                 flag[i] = 1;
//                 return;
//             }
//         }
//         flag[i] = 2;
//     }
// };


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //无出度的节点，无出度不好回溯，求反图，无入度节点
        int n = graph.size();
        vector<vector<int>> reverse_graph(n);
        vector<int> degree(n);
        for (int i = 0; i < n; i++) {
            for (int next : graph[i]) {
                reverse_graph[next].push_back(i);
            }
            degree[i] = graph[i].size();
            // std::cout<< "i: " << i << ", " << degree[i] << "\n";
        }
        
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 0) {
                stk.push(i);
            }
        }
        while (!stk.empty()) {
            int cur = stk.top();
            stk.pop();
            for (int next: reverse_graph[cur]) {
                degree[next] -= 1;
                if (degree[next] == 0) stk.push(next);
            }
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (degree[i] > 0) continue;
            ret.push_back(i);
        }
        return ret;
    }
};
