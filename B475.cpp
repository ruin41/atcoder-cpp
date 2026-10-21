#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int buyCount = 0;

    // 入力
    cin >> buyCount;
    vector<int> goods(buyCount);

    for (int i = 0; i < buyCount; i++) {
        cin >> goods[i];
    }
    // お釣り
    vector<int> change;

    // 計算の処理
    for (int good : goods) {
        int money = 1000;
        while (money < good) {
            money += 1000;
        }
        change.push_back(money - good);
    }

    int S = 0, M = 0, L = 0;

    for (int c : change) {
        for (int i = 0; i < 3; i++) {
            if (i == 0) {
                S += c % 10;
                c = c / 10;
            }
            else if (i == 1) {
                M += c % 10;
                c = c / 10;
            }
            else {
                L += c % 10;
            }
        }
    }

    cout << S << " " <<  M << " " <<  L << endl;
}