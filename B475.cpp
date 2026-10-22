#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int buyCount = 0;

    // 入力
    cin >> buyCount;

    int c1 = 0, c10 = 0, c100 = 0;
    for (int i = 0; i < buyCount; i++) {
        int price;
        cin >> price;
        int change = (((price + 999) / 1000) * 1000) - price;

        c1 += change % 10;
        c10 += (change / 10) % 10; 
        c100 += change / 100;
    }
    cout << c1 << " " <<  c10 << " " <<  c100 << endl;
}