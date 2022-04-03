/*
    第i个station只和第i-1个station是否加油后的状态有关；
*/
// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         if (startFuel >= target) return 0;
//         queue<tuple<int, int>> que;
//         que.push({target - startFuel, 0});
//         int n = stations.size();
//         int ans = n + 1;
//         for (int i = 0; i < n; i++) {
//             vector<int> station = stations[i];
//             int lastChance = que.size();
//             if (lastChance == 0) return -1;
//             for (int j = 0; j < lastChance; j++) {
//                 auto [curFuels, curTimes] = que.front(); que.pop();
//                 if (curFuels > 0 && target - curFuels < station[0]) continue;
//                 //本次加油
//                 if (curFuels <= 0) {
//                     ans = min(ans, curTimes);
//                     continue;
//                 }
//                 que.push({curFuels - station[1], curTimes + 1});
//                 que.push({curFuels, curTimes});
//             }
//             if (ans == 1) return ans;
//         }
//         while (!que.empty()) {
//             auto [curFuels, curTimes] = que.front(); que.pop();
//             if (curFuels <= 0) ans = min(ans, curTimes);
//         }
//         return ans == n + 1 ? -1 : ans;
//     }
// };



// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         if (startFuel >= target) return 0;
//         int n = stations.size();
//         vector<long> dp(n + 1, 0);
//         dp[0] = startFuel;
//         for (int i = 0; i < n; i++) {
//             for (int k = i; k >= 0; k--) {
//                 if (dp[k] >= stations[i][0]) {
//                     dp[k + 1] = max(dp[k + 1], dp[k] + stations[i][1]);
//                 }
//             }
//         }
//         for (int i = 0; i <= n; i++) {
//             if (dp[i] >= target) return i;
//         }
//         return -1;
//     }
// };


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        int n = stations.size();
        priority_queue<int, vector<int>, less<int>> pq;
        int pre = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int distance = stations[i][0];
            int gas = stations[i][1];
            startFuel -= distance - pre;
            while (!pq.empty() && startFuel < 0) {
                startFuel += pq.top();
                pq.pop();
                ans += 1;
            }
            if (startFuel < 0) return -1;
            pq.push(gas);
            pre = distance;
        }
        startFuel -= target - pre;
        while (!pq.empty() && startFuel < 0) {
            startFuel += pq.top();
            pq.pop();
            ans += 1;
        }
        if (startFuel < 0) return -1;
        return ans;
    }
};

