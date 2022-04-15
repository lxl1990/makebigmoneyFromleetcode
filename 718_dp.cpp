/*
    dp[i][j] means the maximum length of the common subarray ended with nums1[i] and nums2[j];
    if nums1[i] = nums2[j]
        dp[i][j] = dp[i-1][j-1] + 1
*/

//class Solution {
//public:
//    int findLength(vector<int>& nums1, vector<int>& nums2) {
//        int ans = 0;
//        vector<int> dp(nums2.size() + 1, 0);
//        for (int i = 0; i < nums1.size(); i++) {
//            int pre = dp[0];
//            for (int j = 0; j < nums2.size(); j++) {
//                int tmp = dp[j + 1];
//                if (nums1[i] == nums2[j]) {
//                    dp[j + 1] = pre + 1;
//                    ans = max(ans, dp[j + 1]);
//                } else {
//                    dp[j + 1] = 0;
//                }
//                pre = tmp;
//            }
//        }
//        return ans;
//    }
//};



/*
    hash + binary search
    为防止越界，做取模处理
    hash(array) = SUM {array[i] * base^(n - (i + 1))}
    mod = 1000000009
    
*/
class Solution {
private:
    int base = 13;
    //int mod = 1000000007;
    int mod = 1000000009;
    long long power(long long x, int pow) {
        long long ret = 1;
        while (pow) {
            if (pow & 1) {
                ret = (ret * x) % mod;
            }
            x =  (x * x) % mod;
            pow >>= 1;
        }
        return ret;
    }
    bool check(vector<int>& nums1, vector<int>& nums2, int len) {
        long long hashValue = 0;
        for (int i = 0; i < len; i++) {
            hashValue = (hashValue * base + nums1[i]) % mod;
        }
        unordered_set<long long> hashSet;
        hashSet.insert(hashValue);
        long long mult = pow(base, len - 1);
        for (int i = len; i < nums1.size(); i++) {
            hashValue = ((hashValue - nums1[i - len] * mult % mod + mod) * base % mod + nums1[i]) % mod;
            hashSet.insert(hashValue);
        }
        hashValue = 0;
        for (int i = 0; i < len; i++) {
            hashValue = (hashValue * base + nums2[i]) % mod;
        }
        if (hashSet.count(hashValue)) return true;
        for (int i = len; i < nums2.size(); i++) {
            hashValue = ((hashValue - nums2[i - len] * mult % mod + mod) * base % mod + nums2[i]) % mod;
            if (hashSet.count(hashValue)) return true;
        }
        return false;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int left = 0, right = min(nums1.size(), nums2.size()) + 1;
        while (left + 1 != right) {
            int mid = left + (right - left) / 2;
            if (!check(nums1, nums2, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        right left;
    }
};
