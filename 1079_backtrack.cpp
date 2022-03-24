// class Solution {
// private:
//     int ans = 0;
// public:
//     int numTilePossibilities(string tiles) {
//         /*
//             字符串排序，分别轮询不同的字符串长度，从1到n，组成不同的字符串组合，并保存结果
//             1: 遍历字符串，遇到相邻相同跳过； 
//             2: 遍历字符串，固定首个元素，然后从后面抽取去重的1个字符长度组合
//             3: 遍历字符串，固定首个元素，然后从后面抽取去重的2个字段长度组合
//             这个过程如果需要保存中间结果，n * n * Ann 每个索引后不同长度的字符组合情况
//             上述方法比较麻烦，需要存字符组合每种情况，但本题只用返回组合个数；
//         */
        
//         /*
//             第二种方法n为title长度
//             生成每个字符个数的map信息表，每个字符贡献个数0-n，遍历每个字符可以贡献的字符个数
//         */
//         unordered_map<char, int> index_map;
//         vector<int> c_cnt;
//         for (char c : tiles) {
//             int index = c_cnt.size();
//             if (index_map.find(c) == index_map.end()) {
//                 index_map[c] = index;
//                 c_cnt.push_back(0);
//             }
//             index = index_map[c];
//             c_cnt[index]++;
//         }
//         index_map.clear();
//         int n = c_cnt.size();
//         // for (int cnt : c_cnt) {
//         //     cout << cnt << ", "; 
//         // }
//         // cout << endl;
//         vector<int> path;
//         dfs(c_cnt, path, 0, n);
//         return ans;
//     }
//     void dfs(vector<int>& c_cnt, vector<int>& path, int index, int n) {
//         // cout<<"index: " << index << ", all: " << all_cnt << endl;
//         if (index == n) {
//             int divisor = 1;
//             int all_cnt = 0;
//             for (int cnt : path) {
//                 // cout << cnt << ", "; 
//                 all_cnt += cnt;
//                 divisor *= permution(cnt);
//             }
//             // cout << "all_cnt: " << all_cnt << ", divisor: " << divisor << ", val: " << permution(all_cnt) / divisor;
//             // cout << endl;
//             if (all_cnt > 0) ans += permution(all_cnt) / divisor;
//             return;
//         }
//         for (int i = 0; i <= c_cnt[index]; i++) {
//             path.push_back(i);
//             dfs(c_cnt, path, index + 1, n);
//             path.pop_back();
//         }
//     }
//     int permution(int n) {
//         int ret = 1;
//         while (n > 1) {
//             ret *= n--;
//         }
//         return ret;
//     }
// };

class Solution {
public:
    int ans = 0;
    void dfs(string &str, vector<int> &visit){
        for (int i = 0; i < str.size();i++){
            if ((i > 0) && (str[i] == str[i - 1] && (visit[i - 1] == 0)))
                continue;
            if(visit[i] == 0){
                visit[i] = 1;
                ans++;
                dfs(str, visit);
                visit[i] = 0;
            }
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        vector<int> visit = vector<int>(tiles.size(), 0);
        sort(tiles.begin(), tiles.end());
        dfs(tiles,visit);

        return ans;
    }
};
