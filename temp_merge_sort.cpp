/* Merge sort.
 * The time-complexity is O(NlogN). */
#include <iostream>

using namespace std;

const int MAX_N = 10005;
double arr[MAX_N];

void merge_sort(int l, int r);

void merge(int l, int m, int r);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> arr[i]; }

    merge_sort(0, n - 1);

    for (int i = 0; i < n; i++) { cout << arr[i] << " "; }
    return 0;
}

void merge_sort(int l, int r) {
    if (l >= r) { return; }
    int m = 0;
    m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    merge(l, m, r);
}

void merge(int l, int m, int r) {  // O(n)
    int i = 0, j = 0;
    double a[m - l + 1], b[r - m];
    copy(arr + l, arr + m + 1, a);
    copy(arr + m + 1, arr + r + 1, b);
    for (int k = l; k <= r; k++) {  // in ascending
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
            if (i == m - l + 1) {
                copy(b + j, b + r - m, arr + l + i + j);
                break;
            }
        } else {
            arr[k] = b[j];
            j++;
            if (j == r - m) {
                copy(a + i, a + m - l + 1, arr + l + i + j);
                break;
            }
        }
    }
}