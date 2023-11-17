#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int num[110][110];

int main() {
    int n, x, i, j, k;
    while (~scanf("%d", &n)) {
        int maxx = -9999999;
        for (i = 1; i <= n; i++)  //算高度和时上边要减一，因此下标从1开始，全局变量，初始化为0
        {
            for (j = 1; j <= n; j++) {
                scanf("%d", &x);
                num[i][j] = num[i - 1][j] + x;  //求这一列前i项数的和
                if (x > maxx)       //单个点的最大值
                    maxx = x;
            }
        }
        for (i = 1; i <= n; i++) //矩形的上边
        {
            for (j = 1; j <= n; j++)  //矩形的下边
            {
                if (i <= j)   //上边要小于等于下边
                {
                    int sum = -0xfffffff;   //连续子序列的最大值初始化位负无穷
                    for (k = 1; k <= n; k++)     //求此时的连续子序列的最大和
                    {
                        int a = num[j][k] - num[i - 1][k];   //用矩形下边的值减去矩形上边的值，代表矩形的这一列的和，
                        if (sum + a < a)    //由于是连续子序列的和，当sum加上这一列的和还没有这一列自身大时，就不要前面的了，sum赋为此时的值
                            sum = a;
                        else      //连续求和
                            sum += a;
                        if (sum > maxx)   //更新最大值
                            maxx = sum;
                    }
                }
            }
        }
        printf("%d\n", maxx);
    }
}