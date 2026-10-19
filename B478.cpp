#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int num = 0;
    int maxPrice = 0;
    cin >> num >> maxPrice;

    vector<int> happy(num);

    // 嬉しさの入力
    for (int i = 0; i < num; i++) {
        cin >> happy[i];
    }
    int maxHappy = 0;

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            for (int k = j + 1; k < num; k++) {

                int sumPrice = (i + 1) + (j + 1) + (k + 1);

                if (sumPrice <= maxPrice) {
                    int sumHappy = happy[i] + happy[j] + happy[k];

                    maxHappy = max(maxHappy, sumHappy);
                }
            }
        }
    }
    cout << maxHappy << endl;
 }