#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define MAX_N 355
int value[MAX_N][MAX_N];
int sum[MAX_N][MAX_N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> value[i][j];
            sum[i][j] = 0;  // reset
            if (i == n - 1) {
                sum[i][j] = value[i][j];  // for the last row
            }
        }
    }

    // 此处需特判
    if (n == 1) {
        printf("%d\n", value[0][0]);
        return 0;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            sum[i][j] = max(sum[i + 1][j], sum[i + 1][j + 1]) + value[i][j];
        }
    }

    printf("%d\n", sum[0][0]);
    return 0;
}