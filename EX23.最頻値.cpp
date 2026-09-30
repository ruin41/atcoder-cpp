#include <queue>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main() {

    int N = 0;
    cin >> N;
    vector<int> IN(N);

    for (int i = 0; i < N; i++) {
        cin >> IN.at(i);
    }

    map<int, int> cnt;
    for (int a:IN) {
        if(cnt.count(a)) {
            cnt.at(a)++;
        }
        else {
            cnt[a] = 1;
        }
    }

    int max = 0, ans = 0;

    for (int b : IN) {
        if (max < cnt.at(b)) {
            max = cnt.at(b);
            ans = b;
        }
    }

    cout << ans << " " << max << endl;
}