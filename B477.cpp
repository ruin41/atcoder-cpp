#include <iostream>
#include <vector>
#include <cstdlib> // 整数用
using namespace std;

int main() {
    int humanNum = 0;
    int lineNum = 0;
    cin >> humanNum >> lineNum;

    vector<int> humanLine;

    // 全員の座標の入力
    for (int i = 0; i < humanNum; i++) {
        cin >> humanLine[i];
    }

    vector<int> lineHuman; // 一線を画した数値

    for (int i = 0; i < humanNum; i++) {
        bool fNoLine = false;
        int cnt2 = 0;
        for (int j = 0; j < humanNum; j++) {

            if (i == j) continue;

            // 座標の差が一線を画さないなら、フラグをON
            if (abs(humanLine[i] - humanLine[j]) < lineNum) {
                fNoLine = true;
                break;
            }
        }
        // 全ての数値と一線を画している場合
        if (!fNoLine) {
            lineHuman.push_back(i + 1);
        }
    }
    // 一線を画した数
    cout << lineHuman.size() << endl;

    // 一線を画した数値全て出力
    for (int HN : lineHuman) {
        cout << HN << " ";
    }
    cout << endl;
}