#include <iostream>
using namespace std;

const int MAX_N = 205;

struct Line {
    int pos_l, pos_r;
};

int cmp(const void* a, const void* b);

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;

        struct Line lines[MAX_N];
        for (int j = 0; j < n; j++) {
            int id_l, id_r;
            cin >> id_l >> id_r;
            if (id_l > id_r) { swap(id_l, id_r); }

            // 将始末房间号转化为线段的左右端点号
            if (id_l % 2 == 1) { lines[j].pos_l = id_l / 2 + 1; }
            else { lines[j].pos_l = id_l / 2; }
            if (id_r % 2 == 1) { lines[j].pos_r = id_r / 2 + 1; }
            else { lines[j].pos_r = id_r / 2; }
        }
        qsort(lines, n, sizeof(Line), cmp);  // 对所有线段进行排序
        //for (int j = 0; j < n; j++) {
        //	cout << lines[j].pos_l << " " << lines[j].pos_r << endl;
        //}

        int cnt = 0;
        bool flag[MAX_N];  // 标记一条线段是否已经被选中
        bool finish = false;
        for (int j = 0; j < n; j++) { flag[j] = false; }
        while (!finish) {
            int pos_last = 0;
            for (int j = 0; j < n; j++) {
                /* 若当前线段的左端位置比上一个被选中的线段的右端位置(pos_last)要大,
                则当前线段可选.同时更新pos_last为当前线段的右端位置.
                */
                if (flag[j] == false) {
                    if (lines[j].pos_l > pos_last) {
                        flag[j] = true;
                        pos_last = lines[j].pos_r;
                    }
                }
            }
            cnt++;

            // 判断是否可以结束(即所有线段都被选过了)
            finish = true;
            for (int j = 0; j < n; j++) {
                if (flag[j] == false) { finish = false; break; }
            }
        }
        cout << 10 * cnt << endl;
    }
}

int cmp(const void* a, const void* b) {
    struct Line* x = (Line*)a;
    struct Line* y = (Line*)b;
    if (x->pos_l != y->pos_l) {
        return x->pos_l - y->pos_l;  // 按左端位置大小升序排
    }
    else {
        return x->pos_r - y->pos_r;  // 若左端位置大小相同, 则按右端位置大小升序排
    }
}
