/*
    dp[i][j][k][0]、dp[i][j][k][1]分别代表代表pizza[i:][j:]最后一刀为横切、竖切分割k刀有多少方案
    1、最后一刀是横着切的话
        dp[i][j][k][0] += (dp[i_next][j][k-1][0] + dp[i_next][j][k-1][1]) * (i_next - i_cur) 中间可以横切的刀数 + dp[i_next][j][k][0];
        其中i_cur为pizza[i:][j:]中有苹果最大的行号, i_next为pizza[i+1:][j:]中有苹果最大的行号

    2、最后一刀是竖着切的话
        dp[i][j][k][1] += (dp[i][j_next][k-1][0] + dp[i][j_next][k-1][1]) * (j_next - j_cur)中间可以竖切的刀数 + dp[i][j_next][k][1];
        其中j_cur为pizza[i:][j:]中有苹果最大的列号, j_next为pizza[i:][j+1:]中有苹果最大的列号 

    dp初始化 主要是把不切的情况定义清楚, 而且不切的情况把1赋值给横向、纵向都一样
    初始化条件：dp[i][j][0][0] = rowHasA[i][j] != -1 : 1 : 0;

    其中rowHasA[i][j] = if pizza[i][j] == 'A' ? i : min(rowHasA[i][j+1], rowHasA[i+1][j]), colHasA[i][j] = if pizza[i][j] == 'A' ? j : min(colHasA[i+1][j], colHasA[i][j+1]);
*/

typedef long long LL;
const long mod = 1e9 + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        if (m == 0) return 0;
        int n = pizza[0].size();
        if (n == 0) return 0;
        vector<vector<int>> rowHasA(m, vector<int>(n, 51));
        vector<vector<int>> colHasA(m, vector<int>(n, 51));
        if (pizza[m - 1][n - 1] == 'A') {
            rowHasA[m - 1][n - 1] = m - 1;
            colHasA[m - 1][n - 1] = n - 1;
        }
        for (int i = m - 2; i >= 0; i--) {
            rowHasA[i][n - 1] = pizza[i][n - 1] == 'A' ? i : rowHasA[i + 1][n - 1];
            colHasA[i][n - 1] = pizza[i][n - 1] == 'A' ? n - 1 : colHasA[i + 1][n - 1];
            // cout << "i: " << i << ", j:" << n - 1 << ", val: " << rowHasA[i][n - 1] << ", " << colHasA[i][n - 1] << endl;
        }
        for (int j = n - 2; j >= 0; j--) {
            rowHasA[m - 1][j] = pizza[m - 1][j] == 'A' ? m - 1 : rowHasA[m - 1][j + 1];
            colHasA[m - 1][j] = pizza[m - 1][j] == 'A' ? j : colHasA[m - 1][j + 1];
            // cout << "i: " << m - 1 << ", j:" << j << ", val: " << rowHasA[m - 1][j] << ", " << colHasA[m - 1][j] << endl;
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                rowHasA[i][j] = pizza[i][j] == 'A' ? i : min(rowHasA[i + 1][j], rowHasA[i][j + 1]);    
                colHasA[i][j] = pizza[i][j] == 'A' ? j : min(colHasA[i + 1][j], colHasA[i][j + 1]);    
                // cout << "i: " << i << ", j:" << j << ", val: " << rowHasA[i][j] << ", " << colHasA[i][j] << endl;
            }
        }
        vector<vector<vector<vector<LL>>>> dp(m, vector<vector<vector<LL>>>(n, vector<vector<LL>>(k, vector<LL>(2, 0)))); 
        //dp初始化 主要是把不切的情况定义清楚, 而且不切的情况把1赋值给横向、纵向都一样
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][0][0] = rowHasA[i][j] > m ? 0 : 1;
                // cout << "i: " << i << ", j:" << j << ", k: " << 0 << ", rowval: " << dp[i][j][0][0] << endl;
            }
        }
        
        for (int kk = 1; kk < k; kk++) {
            for (int i = m - 2; i >= 0; i--) {
                int i_cur = rowHasA[i][n - 1];
                int i_next = i_cur < m - 1 ? rowHasA[i_cur + 1][n - 1] : i_cur;
                if (i_next < m) dp[i][n - 1][kk][0] = (dp[i_next][n - 1][kk-1][0] * (i_next - i_cur) + dp[i_next][n - 1][kk][0]) % mod;
                // cout << "i: " << i << ", j:" << n - 1 << ", k: " << kk << ", rowval: " << dp[i][n - 1][kk][0] << endl;
            }
            for (int j = n - 2; j >= 0; j--) {
                int j_cur = colHasA[m - 1][j];
                int j_next = j_cur < n - 1 ? colHasA[m - 1][j_cur + 1] : j_cur;
                if (j_next < n) dp[m - 1][j][kk][1] = ((dp[m - 1][j_next][kk-1][0] + dp[m - 1][j_next][kk-1][1]) * (j_next - j_cur) + dp[m - 1][j_next][kk][1]) % mod;
                // cout << "i: " << m - 1 << ", j:" << j << ", k: " << kk << ", colval: " << dp[m - 1][j][kk][1] << endl;
            }
            for (int i = m - 2; i >= 0; i--) {
                for (int j = n - 2; j >= 0; j--) {
                    int i_cur = rowHasA[i][j];
                    int i_next = i_cur < m - 1 ? rowHasA[i_cur + 1][j]: i_cur;
                    if (i_next < m) dp[i][j][kk][0] = ((dp[i_next][j][kk-1][0] + dp[i_next][j][kk-1][1]) * (i_next - i_cur) + dp[i_next][j][kk][0]) % mod;
                    // cout << "i: " << i << ", j:" << j << ", k: " << kk << ", rowval: " << dp[i][j][kk][0] << endl;

                    int j_cur = colHasA[i][j];
                    int j_next = j_cur < n - 1 ? colHasA[i][j_cur + 1] : j_cur;
                    if (j_next < n) dp[i][j][kk][1] = ((dp[i][j_next][kk-1][0] + dp[i][j_next][kk-1][1]) * (j_next - j_cur) + dp[i][j_next][kk][1]) % mod;
                    // cout << "i:" << i << ", j:" << j << ", k: " << kk << ", colval: " << dp[i][j][kk][1] << endl;
                }
            }
        }
        return dp[0][0][k - 1][0] + dp[0][0][k - 1][1];
    }
};
