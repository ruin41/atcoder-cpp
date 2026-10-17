#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N = 0;
    cin >> N;

    string weatherRecord = "";
    cin >> weatherRecord;

    int maxRainCount = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (weatherRecord[i] == 'R') {
            count++;
            if (count > maxRainCount) {
                maxRainCount = count;
            }
        }
        else {
            count = 0;
        }
    }

    cout << maxRainCount << endl;
    return 0;
}