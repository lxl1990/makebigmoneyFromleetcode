class Solution {
public:
    std::vector<vector<int>> merge(std::vector<vector<int>>& intervals) {
        std::vector<vector<int>> ret;
        int n = intervals.size();
        if (n == 0) return ret;
        auto myCmp = [](const std::vector<int>& interval1, const std::vector<int>& interval2) {
            return interval1[0] < interval2[0] || (interval1[0] == interval2[0] && interval1[1] < interval2[1]);
        };
        std::sort(intervals.begin(), intervals.end(), myCmp);
        std::vector<int> interval = intervals[0];
        for (int i = 1; i < n; i++) {
            if (interval[1] < intervals[i][0]) {
                ret.emplace_back(interval);
                interval = intervals[i];
            } else {
                interval[1] = std::max(interval[1], intervals[i][1]);
            }
        }
        ret.emplace_back(interval);
        return ret;
    }
};
