class Solution {
private:
    int binarySearch(int n, function<bool(int)> f) {
        int l = -1, r = n;
        while (l + 1 != r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        int n = envelopes.size();
        auto myCmp = [](const auto& e1, const auto& e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0]) && e1[1] > e2[1];
        };
        sort(envelopes.begin(), envelopes.end(), myCmp);
        vector<int> dp = {envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            int num = envelopes[i][1];
            int index = binarySearch(dp.size(), [&](int i) {return dp[i] >= num;});
            if (index == dp.size()) {
                dp.push_back(num);
            } else {
                dp[index] = num;
            }
        }
        return dp.size();
    }
};
