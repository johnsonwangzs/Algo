#include <iostream>

using namespace std;
const int MAX_N = 53;
const int MAX_M = 53;
const int MAX_D = 253;
const int MAX_E = 253;
const int MAX_T = 203;

int main() {
    int N, T, caseCnt = 0;
    while (true) {
        caseCnt++;
        cin >> N;  // 总站台数
        if (N == 0) {
            break;
        }
        cin >> T;  // 见面时间
        int t[MAX_N], M1, M2, d[MAX_M], e[MAX_M];
        for (int i = 1; i <= N - 1; i++) {
            cin >> t[i];  // 每两站之间的乘车时间
        }
        cin >> M1;  // 从站台1发车总数
        for (int i = 1; i <= M1; i++) {
            cin >> d[i];  // 从站台1发车的时间
        }
        cin >> M2;  // 从站台N发车总数
        for (int i = 1; i <= M2; i++) {
            cin >> e[i];  // 从站台N发车的时间
        }

        // 用两个数组分别表示每个站台在某个时刻是否有车停靠/发出
        bool train1[MAX_N][MAX_T] = {}, train2[MAX_N][MAX_T] = {};  // 初始化为false
        for (int i = 1; i <= M1; i++) {  // 遍历所有从站台1发出的车
            int totalTime = d[i];
            train1[1][d[i]] = true;  // 发车时间
            for (int j = 1; j <= N - 1; j++) {
                totalTime += t[j];
                train1[j + 1][totalTime] = true;
            }
        }
        for (int i = 1; i <= M2; i++) {  // 遍历所有从站台n发出的车
            int totalTime = e[i];
            train2[N][e[i]] = true;
            for (int j = N - 1; j >= 1; j--) {
                totalTime += t[j];
                train2[j][totalTime] = true;
            }
        }

        // 初始化dp数组
        int dp[MAX_T][MAX_N];
        for (int i = 0; i <= T; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = -1;
            }
        }

        int totalTime = d[1];
        for (int j = 0; j <= T; j++) {
            dp[j][1] = 0;
        }
        for (int i = 2; i <= N; i++) {
            totalTime += t[i - 1];
            for (int j = totalTime; j <= T; j++) {
                dp[j][i] = t[i - 1];
            }
        }

        // 按时间遍历
        // dp[i][j]：时刻i到达/在站台j，从时刻0开始最长的乘车时间
        for (int i = 0; i < T; i++) {
            for (int j = 1; j <= N; j++) {  //
                if (dp[i][j] != -1) {  // 在有些时刻i，肯定还暂时无法到达站台j
                    dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
                    if (j != N && train1[j][i] && i + t[j] <= T) {
                        dp[i + t[j]][j + 1] = max(dp[i][j] + t[j], dp[i + t[j]][j + 1]);
                    }
                    if (j != 1 && train2[j][i] && i + t[j - 1] <= T) {
                        dp[i + t[j - 1]][j - 1] = max(dp[i][j] + t[j - 1], dp[i + t[j - 1]][j - 1]);
                    }
                }
            }
        }

        if (dp[T][N] == -1) {  // 无法到达
            cout << "Case Number " << caseCnt << ": impossible" << endl;
            continue;
        }
        int minWaitTime = T - dp[T][N];  // 最少等待时间 = 总时间 - 最大在车上时间
        cout << "Case Number " << caseCnt << ": " << minWaitTime << endl;
    }
    return 0;
}

/*
 *
4
55
5 10 15
4
0 5 10 20
4
0 5 10 15

4
18
1 2 3
5
0 3 6 10 12
6
0 3 5 7 12 15
 */