/*
    奇偶跳
*/


/*
    先按照val排序索引，然后遍历排序结果，生成每个索引的奇偶跳next索引
    然后再从后往前遍历，dp[i][0]代表i处奇数跳是否可以达到 dp[i][1]代表i处偶数跳是否可以到达
        dp[i][y] = dp[j][1-y], next[i][y]=j
*/

//class Solution {
//public:
//    int oddEvenJumps(vector<int>& arr) {
//        int n = arr.size();
//        if (n <= 1) return 1;
//        vector<pair<int, int>> new_arr;
//        for (int i = 0; i < n; i++) {
//            new_arr.emplace_back(make_pair(i, arr[i]));
//        }
//        sort(new_arr.begin(), new_arr.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.second == b.second ? a.first < b.first : a.second < b.second;});
//        vector<vector<int>> next(n, vector(2, -1));
//        for (int i = 0; i < n - 1; i++) {
//            int j = i + 1;
//            while (j != n && new_arr[j].first < new_arr[i].first) {
//                j++; 
//            }
//            next[new_arr[i].first][0] = j == n ? -1 : new_arr[j].first;
//        }
//        sort(new_arr.begin(), new_arr.end(), [](const pair<int, int>& a, const pair<int, int>& b){return a.second == b.second ? a.first < b.first : a.second > b.second;});
//        for (int i = 0; i < n - 1; i++) {
//            int j = i + 1;
//            while (j != n && new_arr[j].first < new_arr[i].first) {
//                j++; 
//            }
//            next[new_arr[i].first][1] = j == n ? -1 : new_arr[j].first;
//        }
//        vector<vector<int>> dp(n, vector(2, 0));
//        dp[n - 1][0] = 1;
//        dp[n - 1][1] = 1;
//        int ans = 1;
//        for (int i = n - 2; i >=0; i--) {
//            cout << "i: " << i << ", next[i][0]: " << next[i][0] << ", next[i][1]: " << next[i][1] << endl;
//            if (next[i][0] != -1) dp[i][0] = dp[next[i][0]][1];
//            if (next[i][1] != -1) dp[i][1] = dp[next[i][1]][0];
//            if (dp[i][0] == 1) ans++; 
//        }
//        return ans;
//    }
//};

/*
    单调栈生成next
*/
class Solution {
private:
    vector<int> getNext(vector<int>& order) {
        int n = order.size();
        vector<int> out(n, -1);
        stack<int> stk;
        stk.push(order[0]);
        for (int i = 1; i < n; i++) {
            while (!stk.empty() && stk.top() < order[i]) {
                out[stk.top()] = order[i];
                stk.pop();
            }
            stk.push(order[i]);
        }
        return out;
    }
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 1;
        vector<int> order(n, 0);
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        sort(order.begin(), order.end(), [&](int a, int b){return arr[a] == arr[b] ? a < b : arr[a] < arr[b];});
        vector<int> bigger = getNext(order);
        sort(order.begin(), order.end(), [&](int a, int b){return arr[a] == arr[b] ? a < b : arr[a] > arr[b];});
        vector<int> smaller = getNext(order);

        vector<vector<int>> dp(n, vector(2, 0));
        dp[n - 1][0] = 1;
        dp[n - 1][1] = 1;
        int ans = 1;
        for (int i = n - 2; i >=0; i--) {
            cout << "i: " << i << ", bigger[i]: " << bigger[i] << ", smaller[i]: " << smaller[i] << endl;
            if (bigger[i] != -1) dp[i][0] = dp[bigger[i]][1];
            if (smaller[i] != -1) dp[i][1] = dp[smaller[i]][0];
            if (dp[i][0] == 1) ans++; 
        }
        return ans;
    }
};
