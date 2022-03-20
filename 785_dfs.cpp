class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
            // std::cout<< "i: " << i << "\n";
            if (color[i] == 0 && !isBipartite(graph, color, i, 1)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph, vector<int>& color, int i, int cur_color) {
        if (color[i] != 0 && color[i] * cur_color == -1) return false;
        color[i] = cur_color;
        // std::cout<< "i: " << i  << ", cur_color" << cur_color << ", -1*cur_color: " << -1 * cur_color << "\n";
        for (int next: graph[i]) {
            if (color[next] * cur_color == -1) continue;
            if (color[next] != 0 || !isBipartite(graph, color, next, -1 * cur_color)) return false;

        }
        return true;
    }
    
};
