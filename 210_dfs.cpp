// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         //先学入度为0
//         vector<vector<int>> graph(numCourses);
//         vector<int> degree(numCourses);
//         for (auto prerequisite : prerequisites) {
//             graph[prerequisite[1]].push_back(prerequisite[0]);
//             degree[prerequisite[0]] += 1;
//         }
//         vector<int> ret;
//         stack<int> unrelyed;
//         for (int i = 0; i < numCourses; i++) {
//             if (degree[i] == -1) continue;
//             if (degree[i] == 0) unrelyed.push(i);
//             while (!unrelyed.empty()) {
//                 int cur = unrelyed.top();
//                 unrelyed.pop();
//                 ret.push_back(cur);
//                 degree[cur] = -1;
//                 for (int next : graph[cur]) {
//                     degree[next]--;
//                     if (degree[next] == 0) unrelyed.push(next);
//                 }
//             }
//         }
//         return ret.size() == numCourses ? ret : vector<int>();
//     }
// };


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //深搜
        vector<vector<int>> graph(numCourses);
        for (auto prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, visited, i)) return vector<int>();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int cur) {
        if (visited[cur] > 0) return visited[cur] == 2;
        visited[cur] = 1;
        for (int v : graph[cur]) {
            if (!dfs(graph, visited, v)) return false;
        }
        visited[cur] = 2;
        ret.push_back(cur);
        return true;
    }
private:
    vector<int> ret;
};
