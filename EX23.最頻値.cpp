#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    priority_queue<int> pq;
    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num = 0;
        cin >> num;
        pq.push(num);
    }

    int max = pq.top();
    int count = 0;

    while(!pq.empty()) {
        if (pq.top() == max) count++;
        pq.pop();
    }
    cout << max << " " << count << endl;
}