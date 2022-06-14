class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto myCmp = [](const int x, const int y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        };
        sort(nums.begin(), nums.end(), myCmp);
        string ret = "";
        for (int i = 0; i < nums.size(); i++) {
            ret += to_string(nums[i]);
        }
        if (ret[0] == '0') return "0";
        return ret;
    }
};
