#include <queue>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> data;
    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num = 0, count = 1;
        cin >> num;
        data[num] += count;
    }
    int max = 0;
    for (auto a : data) {
        if (max == 0) {
            max = a.first;
        }
        else if (max < a.first) {
            max = a.first;
        } 
    }
    cout << max << " " << data[max] << endl;
}