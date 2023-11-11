/* Insertion sort.
 * The time-complexity is O(N^2). */
#include <iostream>

using namespace std;

const int MAX_N = 10005;
int arr[MAX_N];

void insertion_sort(int arrLen, int k);

void swap(int *x, int *y);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> arr[i]; }

    insertion_sort(n, n - 1);

    for (int i = 0; i < n; i++) { cout << arr[i] << " "; }
}

void insertion_sort(int arrLen, int k) {
    if (k == 0) { return; }
    // sub-problem
    insertion_sort(arrLen, k - 1);
    // combine
    for (int i = k - 1; i >= 0; i--) {
        if (arr[i + 1] < arr[i]) {  // in ascending
            swap(&arr[i + 1], &arr[i]);
        }
    }
}

void swap(int *x, int *y) {
    int tmp = 0;
    tmp = *x;
    *x = *y;
    *y = tmp;
}