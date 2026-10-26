#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    int N = 0;
    cin >> N;
    vector<int> L;
    for (int i = 0; i < N; i++) {
        int Li = 0;
        cin >> Li;
        L.push_back(Li);
    }
    vector<int> difference;

    // 計算
    for (int i = 0; i < N - 1; i++) {
        int diff = 0, A = 0, B = 0;
        for (int j = 0; j < N; j++) {
            if (i < j) {
                B += L[j];
            }
            else {
                A += L[j];
            }
        }
        diff = A - B;
        difference.push_back(abs(diff));
    }
    int minDiff = 0;
    for (int d : difference) {
        if (minDiff == 0) {
            minDiff = d;
        }
        else if (d < minDiff) {
            minDiff = d;
        }
    }
    cout << minDiff << endl;
}