#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N), B(N);

    for (int& a : A) {
        cin >> a;
    }
    for (int& b : B) {
        cin >> b;
    }

    if (A == B) {
        cout << "Yes" << endl;
        return 0;
    }

    int firstDiff = 0;
    // 最初と最後の不一致位置を探す
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            firstDiff = i;
            break;
        }
    }
    int lastDiff = 0;
    for (int i = N - 1; i > 0; i--) {
        if (A[i] != B[i]) {
            lastDiff = i;
            break;
        }
    }

    // 最初の値を最後の場所に入れる
    vector<int> cpyA = A;
    cpyA.insert(cpyA.begin() + lastDiff + 1, A[firstDiff]);
    cpyA.erase(cpyA.begin() + firstDiff);

    if (cpyA == B) {
        cout << "Yes" << endl;
        return 0;
    }

    // 最後の値を最初の場所に入れる
    vector<int> anotherA = A;
    anotherA.erase(anotherA.begin() + lastDiff);
    anotherA.insert(anotherA.begin() + firstDiff, A[lastDiff]);

    if (anotherA == B) {
        cout << "Yes" << endl;
        return 0;
    }    

    cout << "No" << endl;
    return 0;

}