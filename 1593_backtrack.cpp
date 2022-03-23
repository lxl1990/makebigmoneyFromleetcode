class Solution {
private:
    unordered_map<int, int> cache_map;
    int ans = 0;
public:
    int maxUniqueSplit(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<string> elements;
        backTrack(s, elements, 0, n);
        return ans;
    }
    void backTrack(const string& s, vector<string>& elements, int start, int n) {
        if (elements.size() + s.size() - start < ans) return;
        if (start == n) {
            ans = max(ans, int(elements.size()));
            return;
        };
        if (cache_map.find(start) != cache_map.end()) {
            ans = max(ans, int(elements.size()) + cache_map[start]);
            return;
        }
        for (int end = start + 1; end <= n; end++) {
            string substring = s.substr(start, end - start);
            if (find(elements.begin(), elements.end(), substring) != elements.end()) continue;
            elements.emplace_back(substring);
            backTrack(s, elements, end, n);
            elements.pop_back();
        }
    }
};
