#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 個数の入力
    int N = 0;
    cin >> N;

    // 全項の入力
    vector<int> num;
    for (int i = 0 ; i < N ; i++) {
        int tmp = 0;
        cin >> tmp;
        num.push_back(tmp);
    }

    int cnt = 1;
    int sum = 0;
    for (int n : num) {
        // 偶数項の場合continue
        if ((cnt % 2) != 0) {
            sum += n;
        }
        cnt++;
    }
    cout << sum << endl;
    return 0;
}