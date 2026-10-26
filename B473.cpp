#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    vector<int> card;

    for (int i = 0; i < N; i++) {
        bool isUnique = true;
        int A = 0;
        cin >> A;

        for (auto it = card.begin(); it != card.end(); it++) {
            // 既にカードが登録済みなら、登録済みカードを削除し、フラグをfalseにする
            if (*it == A) {
                card.erase(it);
                isUnique = false;
                break;
            }
        }
        // フラグがtrueの場合、カードを登録する
        if (isUnique) {
            card.push_back(A);
        }
    }

    int sum = 0;
    // 登録済みのカードの合計値を取得する
    for (int a : card) {
        sum += a;
    }

    cout << sum << endl;

    return 0;
}