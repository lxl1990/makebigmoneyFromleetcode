// /*
//     merge sort
// */
// class Solution {
// private:
//     vector<int> ret;
//     vector<int> indexMap;
//     void mergeSort(vector<int>& nums, int l, int r) {
//         if (l >= r) {
//             return;
//         }

//         int mid = l + ((r - l) >> 1);
//         mergeSort(nums, l, mid);
//         mergeSort(nums, mid + 1, r);
//         merge(nums, l, mid, r);
//     }

//     void merge(vector<int>& nums, int l, int mid, int r) {
//         int curIndex = 0;
//         int i = l, j = mid + 1;
//         vector<int> tmpNums(r - l + 1, 0);
//         vector<int> tmpIndex(r - l + 1, 0);
//         while (i <= mid && j <= r) {
//             if (nums[i] <= nums[j]) {
//                 ret[indexMap[i]] += (j - mid - 1);
//                 tmpNums[curIndex] = nums[i];
//                 tmpIndex[curIndex] = indexMap[i];
//                 i++;
//                 curIndex++;
//             } else {
//                 tmpNums[curIndex] = nums[j];
//                 tmpIndex[curIndex] = indexMap[j];
//                 j++;
//                 curIndex++;
//             }
//         }

//         while (i <= mid) { 
//             ret[indexMap[i]] += (j - mid - 1);
//             tmpNums[curIndex] = nums[i];
//             tmpIndex[curIndex] = indexMap[i];
//             i++;
//             curIndex++;
//         }

//         while (j <= r) {
//             tmpNums[curIndex] = nums[j];
//             tmpIndex[curIndex] = indexMap[j];
//             j++;
//             curIndex++;
//         }

//         for (int i = l; i <= r; i++) {
//             indexMap[i] = tmpIndex[i - l];
//             nums[i] = tmpNums[i - l];
//         }
//     }
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         ret = vector<int>(n, 0);
//         indexMap = vector<int>(n);
//         for (int i = 0; i < n; i++) {
//             indexMap[i] = i;
//         }
//         mergeSort(nums, 0, n - 1);
//         return ret;
//     }
// };



/*
    Binary Index Tree
*/
class Solution {
private:
    vector<int> indexMap;
    vector<int> trees;

    void delDuplication(vector<int>& nums) {
        indexMap.assign(nums.begin(), nums.end());
        sort(indexMap.begin(), indexMap.end());
        indexMap.erase(unique(indexMap.begin(), indexMap.end()), indexMap.end());
    }

    int getId(int num) {
        return lower_bound(indexMap.begin(), indexMap.end(), num) - indexMap.begin() + 1;
    }

    int LowBit(int x) {
        return  x & (-x);
    }

    int query(int pos) {
        int ret = 0;
        while (pos > 0) {
            ret += trees[pos];
            pos -= LowBit(pos);
        }
        return ret;
    }

    void update(int pos) {
        while (pos < trees.size()) {
            trees[pos] += 1;
            pos += LowBit(pos);
        }
    }


public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret;
        delDuplication(nums);
        trees = vector<int>(nums.size() + 1, 0);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int id = getId(nums[i]);
            ret.emplace_back(query(id - 1));
            update(id);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
