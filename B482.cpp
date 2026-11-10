#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 5x5の用意
    vector<vector<char>> bingo(5, vector<char>(5));

    // 文字列の入力
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> bingo[i][j];
        }
    }

    // 横の判定
    int maxCount = 0;
    for (int i = 0; i < 5; i++) {
        int widthCnt = 0;
        for (int j = 0; j < 5; j++) {
            if (bingo[i][j] == 'o') {
                widthCnt++;
            }
        }
        if (widthCnt > maxCount) {
            maxCount = widthCnt;
        }
    }

    // 縦の判定
    for (int i = 0; i < 5; i++) {
        int vertCnt = 0;
        for (int j = 0; j < 5; j++) {
            if (bingo[j][i] == 'o') {
                vertCnt++;
            }
        }
        if (vertCnt > maxCount) {
            maxCount = vertCnt;
        }
    }

    // 斜めの判定
    int diagoCnt = 0;
    for (int i = 0; i < 5; i++) {
        if (bingo[i][i] == 'o') {
            diagoCnt++;
        }
    }
    if (diagoCnt > maxCount) {
        maxCount = diagoCnt;
    }

    // 逆回転
    int diagoReverseCnt = 0;
    for (int i = 0; i < 5; i++) {
        int num = 4;

        if (bingo[i][num] == 'o') {
            diagoReverseCnt++;
        }
        num--;
    }

    if (diagoReverseCnt > maxCount) {
        maxCount = diagoReverseCnt;
    }

    if (maxCount == 5) {
        cout << 0 << endl;
    }
    else {
        cout << 5 - maxCount << endl;
    }
    return 0;
}