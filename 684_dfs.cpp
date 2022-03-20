
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //并查集
        vector<int> parent(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            parent[i] = i;
            size.push_back(1);
        }
        for (auto& edge : edges) {
            if (union_node(parent, edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }
        return vector<int>();
    }

    bool union_node(vector<int>& parent, int node1, int node2) {
        int parent1 = find(parent, node1);
        int parent2 = find(parent, node2);
        // std::cout<< "edge: " << node1 << ", " << node2 << "; parent1: " << parent1 << ", parent2: " << parent2 <<"\n";
        if (parent1 == parent2) return true;
        if (size[parent1] > size[parent2]) {
            parent[parent2] = parent1;
            size[parent1] += size[parent2];
        } else {
            parent[parent1] = parent2;
            size[parent2] += size[parent1];
        }
        return false;
    }
    int find(vector<int>& parent, int node) {
        while (parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
private:
    vector<int> size;
};


// class Solution {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         //度  成环的节点度为2
//         vector<int> degree(edges.size() + 1, 0);
//         vector<vector<int>> graph(edges.size() + 1);
//         for (auto& edge: edges) {
//             degree[edge[0]] += 1;
//             degree[edge[1]] += 1;
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
//         stack<int> stk;
//         for (int i = 0; i < graph.size(); i++) {
//             if (degree[i] != 1) continue;
//             stk.push(i);
//             while (!stk.empty()) {
//                 int cur = stk.top();
//                 // std::cout<< "cur:" <<cur << "\n";
//                 stk.pop();
//                 degree[cur] -= 1;
//                 for (int next: graph[cur]) {
//                     degree[next] -= 1;
//                     if (degree[next] == 1) stk.push(next);
//                 }
//             }
//         }
//         for (int i = edges.size() -1; i >=0 ; i--) {
//             if (degree[edges[i][0]] > 1 && degree[edges[i][1]] > 1) return edges[i];
//         }
//         return vector<int>();
//     }
// };

// class Solution {
// public:
//     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
//         vector<vector<int>> graph(edges.size() + 1);
//         for (auto& edge: edges) {
//             vector<int> visited(graph.size(), 0);
//             if (dfs(graph, visited, edge[0], edge[1])) return edge;
//             graph[edge[0]].push_back(edge[1]);
//             graph[edge[1]].push_back(edge[0]);
//         }
//         return vector<int>();
//     }
//     bool dfs(vector<vector<int>> & graph, vector<int>& visited, int node1, int node2) {
//         if (node1 == node2) return true;
//         visited[node1] = 1;
//         for (int node: graph[node1]) {
//             if (visited[node] == 1) continue;
//             if(dfs(graph, visited, node, node2)) return true;
//         }
//         return false;
//     }
// };
