#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N = 0;
    cin >> N;

    vector<int> line(N);

    for (int& value : line) {
        cin >> value;
    }

    int start = 0;
    while (start < N) {
        int end = start;

        while (end + 1 < N && line[end] == line[end + 1]) {
            end++;
        }

        for (int i = start; i <= end; i++) {
            int ans = N;
            
            if (start > 0) {
                ans = min(ans, i - (start - 1));
            }

            if (end + 1 < N) {
                ans = min(ans, (end + 1) - i);
            }

            cout << ans << " ";
        }

        start = end + 1;
    }
}