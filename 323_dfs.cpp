// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> graph(n);
//         vector<int> visited(n, 0);
//         for (auto& edge : edges) {
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 dfs(graph, i, visited);
//                 count++;
//             }
//         }
//         return count;
//     }
//     void dfs(vector<vector<int>>& graph, int i, vector<int>& visited) {
//         visited[i] = 1;
//         for (int j : graph[i]) {
//             if (!visited[j]) {
//                 dfs(graph, j, visited);
//             }
//         }
//     }
// };

// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> graph(n);
//         vector<int> visited(n, 0);
//         for (auto& edge : edges) {
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             if (visited[i]) continue;
//             queue<int> que;
//             que.push(i);
//             while (!que.empty()) {
//                 int cur = que.front();
//                 que.pop();
//                 for (int j : graph[cur]) {
//                     if (visited[j]) continue;
//                     que.push(j);
//                 }
//                 visited[cur] = 1;
//             }
//             count++;
//         }  
//         return count;
//     }

// };

//并查集
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        count = n;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
        for (auto& edge : edges) {
            // std::cout<< "edge: " << edge[0] << ", " << edge[1] << "\n";
            union_node(edge[0], edge[1]);
        }
        return count;
    }
    void union_node(int node1, int node2) {
        int r1 = find(node1);
        int r2 = find(node2);
        if (r1 == r2) return;
        if (size[r1] > size[r2]) {
            parent[r2] = r1;
            size[r1] += size[r2];
        } else {
            parent[r1] = r2;
            size[r2] += size[r1];
        }
        count--;
    }
    int find(int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
private:
     int count = 0;
     vector<int> parent;
     vector<int> size;
};
