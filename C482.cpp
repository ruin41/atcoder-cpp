#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H , W , N , Q;
    cin >> H >> W >> N >> Q;

    vector<int> rows, cols;

    for (int i = 0; i < N; i++) {
        int R , C;
        cin >> R >> C;
        rows.push_back(R);
        cols.push_back(C);
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    for (int i = 0; i < Q; i++) {
        int cmd , a, b;
        cin >> cmd >> a >> b;

        int count = 0;
        switch (cmd)
        {   // 選択
            case 1 :
            
            count = upper_bound(rows.begin(), rows.end(), b)
                     - lower_bound(rows.begin(), rows.end(), a);
            break;

            // 射影
            case 2 :

            count = upper_bound(cols.begin(), cols.end(), b)
                     - lower_bound(cols.begin(), cols.end(), a);
            break;
        }
        cout << count << endl;
    }
}