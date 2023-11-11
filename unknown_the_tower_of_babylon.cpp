#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
struct P {
    int w, d, h;
} p[200];
int a[5];
int n;

bool cmp(P a, P b) {
    if (a.w == b.w) {
        return a.d < b.d;
    }
    return a.w < b.w;
}

int f[200], ans = -1;

int main() {
    int caseCnt = 0;
    while (cin >> n && n) {
        caseCnt++;
        ans = -1;
        memset(f, 0, sizeof(f));
        // 每个立方体共有6种翻转，每种都可视作一种固定长宽高的方块
        for (int i = 1; i <= n; i++) {
            cin >> a[0] >> a[1] >> a[2];
            p[i].w = a[0], p[i].d = a[1], p[i].h = a[2];
            p[i + n].w = a[0], p[i + n].d = a[2], p[i + n].h = a[1];
            p[i + n * 2].w = a[1], p[i + 2 * n].d = a[0], p[i + 2 * n].h = a[2];
            p[i + 3 * n].w = a[1], p[i + 3 * n].d = a[2], p[i + 3 * n].h = a[0];
            p[i + 4 * n].w = a[2], p[i + 4 * n].d = a[0], p[i + 4 * n].h = a[1];
            p[i + 5 * n].w = a[2], p[i + 5 * n].d = a[1], p[i + 5 * n].h = a[0];
        }
        // 先按长排，再按宽排，保证在塔中，排在前面的方块一定不会位于排在后面的方块的下面
        sort(p + 1, p + 6 * n + 1, cmp);
        for (int i = 1; i <= 6 * n; i++) {
            f[i] = p[i].h;  // 以第i个方块为塔的基底
            for (int j = 1; j < i; j++) {
                if (p[i].w > p[j].w && p[i].d > p[j].d) {
                    f[i] = max(f[j] + p[i].h, f[i]);  // 考虑第i个方块f[i]时，其之前的所有方块f[j]都已经最优
                }
            }
            ans = max(f[i], ans);
        }
        cout << "Case " << caseCnt << ": maximum height = " << ans << endl;
    }
    return 0;
}
