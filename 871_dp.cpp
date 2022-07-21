//汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。

沿途有加油站，每个 station[i] 代表一个加油站，它位于出发位置东面 station[i][0] 英里处，并且有 station[i][1] 升汽油。

假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。

当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。

为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。

注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。

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

