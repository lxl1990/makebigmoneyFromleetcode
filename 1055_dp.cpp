/*DP + 二分*/
// class Solution {
// private:
//     int findIndex(vector<int>& v, int tar) {
//         //find the minimum index i from v, which i > tar; if not exist return the minimum of index >= 0;
//         int n = v.size();
//         if (n == 0) return -1;
//         int l = -1, r = n;
//         while (l + 1 != r) {
//             int mid = l + (r - l) / 2;
//             if (v[mid] <= tar) {
//                 l = mid;
//             } else {
//                 r = mid;
//             }
//         }
//         return  (r == n) ? v[0] : v[r];
//     }
// public:
//     int shortestWay(string source, string target) {
//         vector<vector<int>> cSourcePos(26, vector<int>());
//         for (int i = 0; i < source.size(); i++) {
//             cSourcePos[source[i] - 'a'].emplace_back(i);
//         }
//         int ans = 0;
//         int pre = -1;
//         for (int k = 0; k < target.size();k++) {
//             char c = target[k];
//             int cur = findIndex(cSourcePos[c - 'a'], pre);
//             // cout << "k: " << k << ", character: " << c << ", cur: " << cur << endl;
//             if (cur == -1) return -1;
//             if (cur <= pre) ans++;
//             pre = cur;
//         }
//         ans++;
//         return ans;
//     }
// };

/*贪心*/
class Solution {
public:
    int update(const string& target, int i, const string& source) {
        int j = 0;
        while (i < target.size() && j < source.size()) {
            if (target[i] == source[j]) {
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return i;
    }
    int shortestWay(string source, string target) {
        int i = 0;
        int res = 0;
        while (i < target.size()) {
            ++res;
            int t = update(target, i, source);
            if (t == i) return -1;
            i = t;
        }
        return res;
    }
};
