#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int coins_weight[12];  // 设真币的重量为1; 0表示某硬币尚未被确认真假
        for (int j = 0; j < 12; j++) { coins_weight[j] = 0; }
        string coins_left[3], coins_right[3], weighing[3];
        for (int j = 0; j < 3; j++) {
            cin >> coins_left[j] >> coins_right[j] >> weighing[j];

            if (weighing[j] == "even") {  // 利用天平平衡状态, 可以标记真币
                for (int k = 0; k < coins_left[j].length(); k++) {  // 左右两盘硬币数量一定相同
                    coins_weight[coins_left[j][k] - 'A'] = 1;
                    coins_weight[coins_right[j][k] - 'A'] = 1;
                }
            }
        }
        // 遍历所有硬币
        for (int j = 0; j < 12; j++) {
            bool finish = false;
            // 若某硬币尚未被标记为真, 则将其作为假币依次验证每个天平不平衡的情况是否合理
            if (coins_weight[j] == 0) {
                int cur_coins_weight[12];
                for (int k = 0; k < 12; k++) { cur_coins_weight[k] = 1; }

                // 对于每个天枰不平衡的情况, 计算左右盘重量并验证是否符合观测到的事实
                cur_coins_weight[j] = 0;  // 先考虑假币轻的情况
                bool flag = true;
                for (int k = 0; k < 3; k++) {
                    int weight_left = 0, weight_right = 0;
                    if (weighing[k] != "even") {
                        for (int m = 0; m < coins_left[k].length(); m++) {
                            weight_left += cur_coins_weight[coins_left[k][m] - 'A'];
                        }
                        for (int m = 0; m < coins_right[k].length(); m++) {
                            weight_right += cur_coins_weight[coins_right[k][m] - 'A'];
                        }
                        if (((weight_left > weight_right) && weighing[k] == "up") or
                            ((weight_left == weight_right) && weighing[k] == "even") or
                            ((weight_left < weight_right) && weighing[k] == "down")) {
                            flag = true;
                        }
                        else {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    printf("%c is the counterfeit coin and it is %s.\n", j + 'A', "light");
                    finish = true;
                }
                if (!finish) {  // 再考虑假币重的情况
                    flag = true;
                    cur_coins_weight[j] = 2;
                    for (int k = 0; k < 3; k++) {
                        int weight_left = 0, weight_right = 0;
                        if (weighing[k] != "even") {
                            for (int m = 0; m < coins_left[k].length(); m++) {
                                weight_left += cur_coins_weight[coins_left[k][m] - 'A'];
                            }
                            for (int m = 0; m < coins_right[k].length(); m++) {
                                weight_right += cur_coins_weight[coins_right[k][m] - 'A'];
                            }
                            if (((weight_left > weight_right) && weighing[k] == "up") or
                                ((weight_left == weight_right) && weighing[k] == "even") or
                                ((weight_left < weight_right) && weighing[k] == "down")) {
                                flag = true;
                            }
                            else {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        printf("%c is the counterfeit coin and it is %s.\n", j + 'A', "heavy");
                        finish = true;
                    }
                }
                if (finish) { break; }
            }
        }
    }
}