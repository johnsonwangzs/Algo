//
// 最长回文子串
//
#include <iostream>

using namespace std;

const int MAX_L = 1005;
bool dp[MAX_L][MAX_L];

int main() {
    string s;
    cin >> s;
    int start = 0, len = 0;  // 记录最长回文子串的起始位置和长度

    // 初始化
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < s.length(); j++) {
            dp[i][j] = false;
        }
    }

    // dp[i][j]:从第i个字符到第j个字符是不是回文子串
    for (int i = s.length() - 1; i >= 0; i--) {
        for (int j = i; j < s.length(); j++) {
            // 检查dp[i][j]是不是回文串
            if (s[i] == s[j]) {
                // 单个字符是回文串（i=j）
                // 两个相邻且相同的字符是回文串（j-i=1）
                // 左右字符相同，且中间字符串是回文串的，整体也是回文串
                if (j - i <= 1 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
                if (dp[i][j] && j - i + 1 > len) {
                    len = j - i + 1;
                    start = i;
                }
            }
        }
    }
    cout << len << " " << start << endl;
}
