#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int N = 0;
    int K = 0;
    cin >> N >> K;
    vector<int> point(N);

    for (int i = 0; i < N; i++) {
        cin >> point[i];
    }
    int count = 0;
    // 一致する点をカウントする
    for (const int& p : point) {
        if (p == K) count++;
    }

    // 線上に一致する点をカウントする
    for (int i = 0; i < N - 1; i++) {
        if (((point[i] < K) && (K < point[i + 1])) || 
        ((point[i] > K) && (K > point[i + 1]))) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}