#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node {
    int id;
    double day, fine;
    double price;
}arr[1005];
bool cmp(Node a, Node b) {
    if (a.price != b.price) {
        return a.price > b.price;
    } else {
        return a.id < b.id;
    }
}
int main() {
    int N, T;
    scanf("%d", &T);
    while (T--) {
        scanf ("%d", &N);
        for (int i = 1; i <= N; i ++) {
            arr[i].id = i;
            scanf("%lf%lf", &arr[i].day, &arr[i].fine);
            arr[i].price = arr[i].fine / arr[i].day;
        }
        sort(arr + 1, arr + N + 1, cmp);
        for (int i = 1; i <= N; i ++) {
            if (i == 1) {
                printf("%d", arr[i].id);
            } else {
                printf(" %d", arr[i].id);
            }
        }
        printf("\n");
        if (T) {
            printf("\n");
        }
    }
    return 0;
}