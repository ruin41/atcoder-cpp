#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    // 人数の入力
    int N = 0;
    cin >> N;
    map<string, int> workSheet;

    for (int i = 0; i < N; i++) {
        // 文字列の入力
        string str = "";
        cin >> str;

        // 全て小文字に変換する。
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        // 文字列のカウントを増やす
        workSheet[str]++;
    }
    int maxCount = 0;
    for (const auto& [s, cnt] : workSheet) {
        maxCount = max(cnt, maxCount);
    }
    cout << maxCount << endl;

}