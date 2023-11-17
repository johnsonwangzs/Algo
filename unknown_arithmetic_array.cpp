#include <iostream>

using namespace std;
const int MAX_N = 55;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a[MAX_N], sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (n == sum) {
            cout << "0" << endl;
        } else if (n > sum) {
            cout << "1" << endl;  // 用1个数把差值补全
        } else {
            cout << sum - n << endl;  // 补一堆0
        }
    }
    return 0;
}