#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // ボールの個数の入力
    int N = 0;
    cin >> N;

    map<int, int> ballColler;
    for (int i = 0; i < N; i++) {
        // 色の入力
        int collor = 0;
        cin >> collor;
        // 色のカウントを増やす
        ballColler[collor]++;
    }
    int maxCount = 0;
    for (auto [collor, count] : ballColler) {
        maxCount = max(count, maxCount);
    }

    cout << N - maxCount << endl;
}