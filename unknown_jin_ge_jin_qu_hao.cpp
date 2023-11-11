#include <iostream>

using namespace std;

const int MAX_N = 55;
const int JINGEJINQU_T = 678;
const int MAX_T = 180 * 50 + JINGEJINQU_T + 5;
int maxSingSong[MAX_N][MAX_T], maxSingTime[MAX_N][MAX_T];

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n, t, a[MAX_N];
        cin >> n >> t;
        for (int j = 1; j <= n; j++) {
            cin >> a[j];
            for (int k = 1; k <= t; k++) {
                maxSingSong[j][k] = 0;
                maxSingTime[j][k] = 0;
            }
        }
        // maxSingSong[j][k]：剩余时间为k时，在前j首歌里选，最多能唱多少首歌
        // maxSingTime[j][k]：剩余时间为k时，在前j首歌里选，最多能唱多长时间
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= t; k++) {
                maxSingSong[j][k] = (j == 1 ? 0 : maxSingSong[j - 1][k]);
                maxSingTime[j][k] = (j == 1 ? 0 : maxSingTime[j - 1][k]);
                if (k > a[j]) {
                    if (maxSingSong[j][k] < maxSingSong[j - 1][k - a[j]] + 1 ||
                        maxSingSong[j][k] == maxSingSong[j - 1][k - a[j]] + 1 &&
                        maxSingTime[j][k] < maxSingTime[j - 1][k - a[j]] + a[j]) {
                        maxSingSong[j][k] = maxSingSong[j - 1][k - a[j]] + 1;
                        maxSingTime[j][k] = maxSingTime[j - 1][k - a[j]] + a[j];
                    }
                }
            }
        }
        cout << "Case " << i + 1 << ": ";
        cout << maxSingSong[n][t] + 1 << " " << maxSingTime[n][t] + JINGEJINQU_T << endl;
    }
}
