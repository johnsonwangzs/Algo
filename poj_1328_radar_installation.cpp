#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define MAX_ISLANDS 1000

struct Line {
    double lx, rx;
};

int cmp(const void* a, const void* b);

int main() {
    int case_cnt = 0;
    while (true) {
        bool finish = false;  // flag of special judgement
        case_cnt++;
        int n, d;
        cin >> n >> d;
        if (n == 0 && d == 0) { return 0; }
        struct Line lines[MAX_ISLANDS];

        // cast each island to a line in x-axis, with coordinate [lx,rx]
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            if (y > d || d < 0 || y < 0) {  // special judgement
                finish = true;
            }
            double l = sqrt(pow(d, 2) - pow(y, 2));
            lines[i].lx = x - l;
            lines[i].rx = x + l;
        }

        if (finish) { printf("Case %d: -1\n", case_cnt); continue; }

        // initializa the flag array, which records whether an island is deleted
        bool flag[MAX_ISLANDS];
        for (int i = 0; i < n; i++) { flag[i] = true; }

        // delete useless islands. the remaining islands would not have "wrapped" relation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && flag[i] == true && flag[j] == true) {
                    if (lines[i].lx >= lines[j].lx && lines[i].rx <= lines[j].rx) {
                        flag[j] = false;
                    }
                }
            }
        }
        struct Line lines_remain[MAX_ISLANDS];
        int cnt_remain_lines = 0;
        for (int i = 0; i < n; i++) {
            if (flag[i]) {
                lines_remain[cnt_remain_lines].lx = lines[i].lx;
                lines_remain[cnt_remain_lines].rx = lines[i].rx;
                cnt_remain_lines++;
            }
        }

        // try to locate radar stations, according to the positions of remaining islands
        qsort(lines_remain, cnt_remain_lines, sizeof(Line), cmp);
        bool flag_remain_lines[MAX_ISLANDS];
        for (int i = 0; i < cnt_remain_lines; i++) { flag_remain_lines[i] = true; }
        int cnt_radar = 0;
        for (int i = 0; i < cnt_remain_lines; i++) {
            if (flag_remain_lines[i]) {  // if this island hasn't been deleted
                double new_radar_pos = lines_remain[i].rx;
                cnt_radar++;
                for (int j = i + 1; j < cnt_remain_lines; j++) {
                    if (lines_remain[j].lx <= new_radar_pos) {
                        flag_remain_lines[j] = false;
                    }
                }
                flag_remain_lines[i] = false;
            }
        }
        printf("Case %d: %d\n", case_cnt, cnt_radar);
    }
}

int cmp(const void* a, const void* b) {
    struct Line* m = (Line*)a;
    struct Line* n = (Line*)b;
    //if (m->rx != n->rx) {
    //    if (m->rx > n->rx) { return 1; }
    //    else { return -1; }
    //}
    if (m->lx != n->lx) {
        if (m->lx > n->lx) { return 1; }
        else { return -1; }
    }
    else {
        return 0;
    }
}