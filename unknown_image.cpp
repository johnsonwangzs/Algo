#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string f1, f2;
        cin >> f1 >> f2;
        int cnt = 0;
        if (f1[0] == f1[1]) {
            cnt = 1;
        } else {
            cnt = 2;
        }
        if (f1.find(f2[0]) == f1.npos) {
            cnt++;
        }
        if (f2[0] != f2[1] && f1.find(f2[1]) == f1.npos) {
            cnt++;
        }
        cout << cnt - 1 << endl;
    }
    return 0;
}