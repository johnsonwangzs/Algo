//
// 01背包问题
//
#include <iostream>
using namespace std;
const int MAX_N = 100, MAX_W = 100;
int dp[MAX_N + 1][MAX_W + 1];
int value[MAX_N], weight[MAX_N];  // n个物品的价值和重量

void item_chosen(int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (dp[i][j] == dp[i - 1][j - weight[i]] + value[i]) {
        cout << i << " ";  // 重量不同，说明选了第i个物品
    } else {
        item_chosen(i - 1, j);
    }
}

int main() {
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> value[i] >> weight[i];
    }

    // dp[i][j]表示从前i个物品种选择物品放入背包，背包的剩余空间为j，最大能放入物品的数量
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= w; j++) {
            // dp[i-1][j]:第i个物品不选，背包的剩余空间仍为j
            dp[i][j] = dp[i - 1][j];
            if (j - weight[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[n][w] << endl;  // 输出n个物品、w空间背包，最多放入物品的数量

    // 回溯得到选择的物品
    item_chosen(n, w);
}
