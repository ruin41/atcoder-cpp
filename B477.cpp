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
        int HN = 0;
        cin >> HN;
        humanLine.push_back(HN);
    }

    int lineHumanNum = 0; // 一線を画した数値の数
    vector<int> lineHuman; // 一線を画した数値
    int cnt1 = 0, cnt2 = 0;
    for (int num : humanLine) {
        cnt1++;
        bool fNoLine = false;
        int cnt2 = 0;
        for (int num2 : humanLine) {
            cnt2++;
            if (cnt1 == cnt2) continue;

            // 座標の差が一線を画さないなら、フラグをON
            if (abs(num - num2) < lineNum) {
                fNoLine = true;
                break;
            }
        }
        // 全ての数値と一線を画している場合
        if (!fNoLine) {
            lineHumanNum++;
            lineHuman.push_back(cnt1);
        }
    }
    // 一線を画した数
    cout << lineHumanNum << endl;

    // 一線を画した数値全て出力
    for (int HN : lineHuman) {
        cout << HN << " ";
    }
    cout << endl;
}