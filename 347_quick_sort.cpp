class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        vector<pair<int, int>> values;
        for (auto& kv : map) {
            values.emplace_back(kv);
        }

        vector<int> ret;
        getTopK(values, 0, values.size() - 1, k, ret);
        return ret;
    }

    void getTopK(vector<pair<int, int>>& values, int start, int end, int k, vector<int>& ret) {
        int index = partition(values, start, end);
        if (index - start >= k) {
            getTopK(values, start, index - 1, k, ret);
        } else {
            for (int i = start; i <= index; i++) {
                ret.emplace_back(values[i].first);
            }
            if (k > index - start + 1) {
                getTopK(values, index + 1, end, k - (index - start + 1), ret);
            }
        }
    }

    int partition(vector<pair<int, int>>& values, int start, int end) {
        int rand = std::rand() % (end - start + 1) + start;
        swap(values[start], values[rand]);
        int pivot = values[start].second;

        int i = start + 1, j = end;
        while (i <= j) {
            while (i <= j && values[i].second > pivot) i++;
            while (values[j].second < pivot) j--;
            if (i > j) break;
            swap(values[i], values[j]);
            i++;
            j--;
        }
        swap(values[start], values[j]);

        return j;
    }
};


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> map;
//         for (int num : nums) {
//             map[num]++;
//         }
//         vector<vector<int>> values(nums.size() + 1);
//         for (auto& kv : map) {
//             values[kv.second].emplace_back(kv.first);
//         }
//         // cout << values.size();

//         vector<int> ret;
//         for (int i = values.size() - 1; i >= 0; i--) {
//             for (int j = 0; j < values[i].size(); j++) {
//                 ret.emplace_back(values[i][j]);
//             }
//             if (ret.size() == k) break;
//         }
//         return ret;
//     }
// };
