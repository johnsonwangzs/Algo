#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, d, a, b;
        cin >> s >> d;
        if (s < 0 || d < 0 || d > s || (s + d) % 2 == 1) {
            cout << "impossible" << endl;
            continue;
        }
        a = (s + d) / 2;
        b = (s - d) / 2;
        if (b < 0) {
            cout << "impossible" << endl;
        } else {
            cout << a << " " << b << endl;
        }
    }
    return 0;
}