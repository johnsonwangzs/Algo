#include <iostream>

using namespace std;
const int MAX_N = 1005;
struct Dual {
    int x;
    int y;
} dual[MAX_N];

int compare(const void *a, const void *b) {
    return (((Dual*)a)->x - ((Dual*)b)->x);  // 升序排序
}

int main() {
    int s, n;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        cin >> dual[i].x >> dual[i].y;
    }

    // dragon按strength从小到大排序
    qsort(dual, n, sizeof(Dual), compare);

    // 从strength最小的龙开始打，直到全打完（yes）或打不了（no）
    int totalS = s;
    for (int i = 0; i < n; i++) {
        if (totalS > dual[i].x) {
            totalS += dual[i].y;
            continue;
        }
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}