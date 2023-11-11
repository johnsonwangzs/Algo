#include <iostream>

using namespace std;
const int MAX_N = 4;
const int MAX_W = 7;  // max(n) = 4

void calc_weight(char c[][MAX_N], int n, int w[][MAX_N]);

int count(int n, int w[][MAX_N]);

int main() {
    int n;

    while (true) {
        cin >> n;
        if (n == 0) break;
        char city[MAX_N][MAX_N];
        int weight[MAX_N][MAX_N];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> city[i][j];
                weight[i][j] = 0;
            }
        }
        calc_weight(city, n, weight);
        cout << count(n, weight) << endl;
    }
    return 0;
}

void calc_weight(char c[][MAX_N], int n, int w[][MAX_N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] == 'X') {
                w[i][j] = -1;
                continue;
            }
            for (int k = j + 1; k < n; k++) {  // towards right
                if (c[i][k] == 'X') break;
                w[i][j]++;
            }
            for (int k = j - 1; k >= 0; k--) {  // towards left
                if (c[i][k] == 'X') break;
                w[i][j]++;
            }
            for (int k = i + 1; k < n; k++) {  // towards down
                if (c[k][j] == 'X') break;
                w[i][j]++;
            }
            for (int k = i - 1; k >= 0; k--) {  // towards up
                if (c[k][j] == 'X') break;
                w[i][j]++;
            }
        }
    }
}

int count(int n, int w[][MAX_N]) {
    int ri = 0, rj = 0, flag[MAX_N][MAX_N] = {0}, count_pos = 0;
    while (true) {  // 每轮选一个位置
        int minW = MAX_W;
        bool flag_t = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (w[i][j] < minW && w[i][j] != -1 && flag[i][j] == 0) {
                    minW = w[i][j];
                    ri = i;
                    rj = j;
                    flag_t = false;
                }
            }
        }
        if (!flag_t) {
            count_pos++;
//            cout << ri <<" " << rj <<endl;
            flag[ri][rj] = -1;
            for (int k = rj + 1; k < n; k++) {  // towards right
                if (w[ri][k] == -1) break;
                flag[ri][k] = -1;
            }
            for (int k = rj - 1; k >= 0; k--) {  // towards left
                if (w[ri][k] == -1) break;
                flag[ri][k] = -1;
            }
            for (int k = ri + 1; k < n; k++) {  // towards down
                if (w[k][rj] == -1) break;
                flag[k][rj] = -1;
            }
            for (int k = ri - 1; k >= 0; k--) {  // towards up
                if (w[k][rj] == -1) break;
                flag[k][rj] = -1;
            }
        }
        if (flag_t) {
            return count_pos;
        }
    }
}
