#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n % 2 == 0) {
            int n2 = n * n;
            int x = n2 / 2 - 1;
            int ans = x + n;
            cout << ans << endl;
        }
        else if (n % 2 == 1) {
            int n2 = n * n;
            int x = n2 / 2;
            int ans = x + n;
            cout << ans << endl;
        }
    }
    return 0;
}
