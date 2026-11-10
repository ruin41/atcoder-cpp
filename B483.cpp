#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N = 0, Q = 0;
    cin >> N >> Q;
    
    vector<vector<int>> ans(Q + 1);
    for (int i = 0; i < N; i++) {
        ans[0].push_back(i + 1);
    }

    for (int i = 0; i < Q; i++) {
        int cmd = 0;
        cin >> cmd;

        // 操作した要素を反転して入れる
        for (int j = cmd - 1; j >= 0; j--) {
            ans[i + 1].push_back(-ans[i][j]);
        }
        // 操作しない余った要素を入れる
        for (int k = cmd; k < N; k++) {
            ans[i + 1].push_back(ans[i][k]);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[Q][i] << endl;
    }

}