#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        long long int dp[110][110];
        long long int Map[110][110];
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m;j++)
            {
                scanf("%lld",&Map[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));          //  dp 数组  ，初始化为 0
        int path[110][110] = {0};           //  保存路径的数组，初始化为 0
        for(int i = m;i >= 1;i--)                    //  两层循环 ， 第一层表示第几列  ，倒着往前推求最小值。类似于数塔
        {
            for(int j = 1;j <= n;j++)
            {
                dp[j][i] = dp[j][i + 1] + Map[j][i];          //  将正后的当做最小值，然后跟下面的进行一个比较
                path[j][i] = j;                               //   记录 路径
                if(j > 1 && dp[j - 1][i + 1] + Map[j][i] <= dp[j][i])       //  如果 j 大于 1 ，那么就可以走 j - 1 的位置，然后就判断 j - 1 的位置符合不符合，符合的话进行一个更新，因为 j - 1 比 j 小，所以 这里的判断需要加上 “ = ” 号，下面 等于 n 的时候也是同理，下面就不谢了
                {
                    dp[j][i] = dp[j - 1][i + 1] + Map[j][i];
                    path[j][i] = j - 1;
                }
                if(j < n && dp[j + 1][i + 1] + Map[j][i] < dp[j][i])     //  如果小于 n ， 那么就可以走 j + 1 的位置，同样进行判断
                {
                    dp[j][i] = dp[j + 1][i + 1] + Map[j][i];
                    path[j][i] = j + 1;
                }
                if(j == 1 && dp[n][i + 1] + Map[j][i] < dp[j][i])       // 因为 1 和 n 都比较特殊，所以，再加上一个判断
                {
                    dp[j][i] = dp[n][i + 1] + Map[j][i];
                    path[j][i] = n;
                }
                if(j == n && dp[1][i + 1] + Map[j][i] <= dp[j][i])
                {
                    dp[j][i] = dp[1][i + 1] + Map[j][i];
                    path[j][i] = 1;
                }
            }
        }
        long long int ans = dp[1][1];
        int Min_i = 1;
        for(int i = 1;i <= n;i++)           // 遍历一遍，寻找出最小值
        {
            if(ans > dp[i][1])
            {
                Min_i = i;
                ans = dp[i][1];
            }
        }
        for(int i = 1;i <= m;i++)        //  根据标记的路径，依次输出路径
        {
            if(i > 1)
                cout << " ";
            cout << Min_i;
            Min_i = path[Min_i][i];    //  将下一个位置赋值给 Min_i
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}