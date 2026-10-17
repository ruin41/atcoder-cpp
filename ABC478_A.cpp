#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 0;
    // 人数の入力
    cin >> N;
    if ((N < 1) && (N > 100)) {
        cout << "1~100で入力してください" << endl;
        return 0;
    }
    int M = 0;
    // ぶどうの粒の入力
    cin >> M;
    if ((M < 1) && (M > 10000)) {
        cout << "1~10000で入力してください" << endl;
        return 0;
    }

    vector<int> grapeNum(N, 0);

    while (M > 0) {
        for (int i = 0; i < N; i++) {
            // 一粒与える
            grapeNum[i] += 1;
            // 総数から一粒減らす
            M--;
            if (M < 1) break;
        }
    }
    for (int j = 0; j < N; j++) {
        cout << grapeNum[j] << endl;
    }
    return 0;
}