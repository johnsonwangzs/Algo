#include<iostream>

using namespace std;
const int INF = 2147483647;
int main() {
    long long n, x, tmp = 0, sum = 0, max_neg = -INF;
    bool flag = true;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (tmp > 0) {
            tmp += x;
        }
        else {
            tmp = x;
        }
        if (tmp > sum) {
            sum = tmp;
        }
        if (x > 0) {
            flag = false;
        }
        if (max_neg < x) {
            max_neg = x;
        }
    }
    if (flag) {
        sum = max_neg;
    }
    cout << sum << endl;
    return 0;
}

