#include <iostream>

using namespace std;
const int MAX_N = 20005;
const int MAX_M = 20005;
int headsDiameter[MAX_N], knightsHeight[MAX_M];

int compare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );  // 升序排序
}

int main() {
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        for (int i = 0; i < n; i++) {
            cin >> headsDiameter[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> knightsHeight[i];
        }

        // 分别排序
        qsort(headsDiameter, n, sizeof(int), compare);
        qsort(knightsHeight, m, sizeof(int), compare);

        int i = 0, j = 0, totalCoins = 0;
        while (i < n && j < m) {
            if (headsDiameter[i] <= knightsHeight[j]) {  // 第j个knights可以砍掉第i个头
                totalCoins += knightsHeight[j];
                i++;
                j++;
                continue;
            }
            j++;  // 考虑下一个knights
        }

        if (i == n) {
            cout << totalCoins << endl;
        } else {
            cout << "Loowater is doomed!" << endl;
        }

        cin >> n >> m;
    }

    return 0;
}