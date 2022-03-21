/*
输入：n = 4, k = 2
输出：
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

输入：n = 1, k = 1
输出：[[1]]

1 <= n <= 20
1 <= k <= n
*/

//class Solution {
//public:
//    vector<vector<int>> combine(int n, int k) {
//        vector<vector<int>> ret;
//        if (n == 0 || k == 0) return ret;
//        vector<int> subset;
//        backtrack(ret, 1, n, k, subset);
//        return ret;
//    }
//    void backtrack(vector<vector<int>>& ret, int start, int maximum, int target, vector<int>& subset) {
//        if (target == 0) {
//            ret.push_back(subset);
//            return;
//        }
//        if (start > maximum || maximum - start + 1 < target) return;
//        subset.push_back(start);
//        backtrack(ret, start + 1, maximum, target - 1, subset);
//        subset.pop_back();
//        backtrack(ret, start + 1, maximum, target, subset);
//    }
//};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (n == 0 || k == 0) return ret;
        vector<int> tmp;
        for (int i = 1; i <= k; i++) {
            tmp.push_back(i);
        }
        tmp.push_back(n+1);
        int j = 0;
        while (j < k) {
            ret.emplace_back(tmp.begin(), tmp.begin() + k);
            j = 0;
            while (j < k && tmp[j] + 1 == tmp[j + 1]) {
                tmp[j] = j + 1;
                j++;
            }
            tmp[j]++;
        }
        return ret;
    }
};
