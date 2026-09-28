#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
    vector<pair<int, int>> data;
int N = 0;
cin >> N;
    for (int i = 0; i < N; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        data.push_back(make_pair(b, a));
    }
    sort(data.begin(), data.end());

    for (pair<int, int> t : data) {
        int b, a;
        tie(b, a) = t;
        cout << a << " " << b << endl;
    }
}