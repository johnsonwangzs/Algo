#include <iostream>

using namespace std;
const int MAX_L = 1005;
bool dp[MAX_L][MAX_L];

int main() {
    int n;
    cin >> n;

    for (int t = 0; t < n; t++) {
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                dp[i][j] = false;
            }
        }

        // 首先找出所有可能的回文子串
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                // dp[i][j]:从第i个字符到第j个字符是不是回文子串
                if (s[i] == s[j]) {
                    // 单个字符是回文串（i=j）
                    // 两个相邻且相同的字符是回文串（j-i=1）
                    // 左右字符相同，且中间字符串是回文串的，整体也是回文串
                    if (j - i <= 1 || dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }

        // 从头开始遍历每个字符位
        int minCnt[MAX_L];
        minCnt[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            minCnt[i] = minCnt[i - 1] + 1;  // minCnt[i]最大只能这么大（对应情况：s[i]不在任何回文子串内）
            for (int j = 0; j <= i; j++) {
                if (dp[j][i]) {  // 如果从j到i的子串是回文的
                    if (j == 0) {
                        minCnt[i] = 1;  // 从0到i的子串整个都是回文的
                    } else if (minCnt[i] > minCnt[j - 1] + 1) {
                        minCnt[i] = minCnt[j - 1] + 1;
                    }
                }
            }
        }
        cout << minCnt[s.length() - 1] << endl;
    }
}