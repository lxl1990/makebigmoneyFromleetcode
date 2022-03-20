class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            //深搜判断
            vector<vector<int>> graph(numCourses);
            for (auto& prerequisite : prerequisites) {
                graph[prerequisite[1]].push_back(prerequisite[0]);
            }
            vector<int> visited(numCourses, 0);
            for (int i = 0; i < numCourses; i++) {
                if (!dfs(graph, visited, i)) return false;
            }
            return true;
        }
        bool dfs(vector<vector<int>>& graph, vector<int>& visited, int cur) {
            if (visited[cur] > 0) return visited[cur] == 2;
            visited[cur] = 1;
            for (int v : graph[cur]) {
                if (!dfs(graph, visited, v)) return false;
            }
            visited[cur] = 2;
            return true;
        }
};
