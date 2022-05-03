/*树状数组*/
class Solution {
private:
    vector<int> tree = vector<int>(30001, 0);
    int MAXN;
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int n, int k) {
        for (int i = n; i <= MAXN; i += lowbit(i)) {
            tree[i] ^= k;
        }
    }
    int query(int a) {
        int ans = 0;
        for (int i = a; i > 0; i -= lowbit(i)) {
            ans ^= tree[i];
        }
        return ans;
    }
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        MAXN = arr.size();
        for (int i = 0; i < MAXN; i++) {
            add(i + 1, arr[i]);
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.emplace_back(query(queries[i][1] + 1) ^ query(queries[i][0]));
        }
        return ans;
    }
};
