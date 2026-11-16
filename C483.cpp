
#include <iostream>
#include <vector>
using namespace std;

struct Candidate {
    int id;
    int votes;
};

// 得票数が多い方を優先。同票なら番号が小さい方を優先。
bool better(const Candidate& a, const Candidate& b) {
    if (a.votes != b.votes) {
        return a.votes > b.votes;
    }
    return a.id < b.id;
}

int main() {
    int n, m;
    cin >> n >> m;

    // a[i]：候補者iが辞退したとき、票が移動する候補者
    vector<vector<int>> a(n);

    // b[i]：候補者iの通常時の得票数
    vector<int> b(n, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        --x;
        --y;

        a[x].push_back(y);
        b[x]++;
    }

    // 通常時の得票数が多い上位2人を求める
    Candidate first = {-1, -1};
    Candidate second = {-1, -1};

    for (int i = 0; i < n; i++) {
        Candidate current = {i, b[i]};

        if (better(current, first)) {
            second = first;
            first = current;
        }
        else if (better(current, second)) {
            second = current;
        }
    }

    // 各候補者が辞退した場合を調べる
    for (int i = 0; i < n; i++) {
        int sz = a[i].size();

        // 辞退者の票を移動先に加算
        for (int v : a[i]) {
            b[v]++;
        }

        // 辞退者の得票数を0にする
        b[i] = 0;

        Candidate winner = {-1, -1};

        // 勝者候補を比較する
        auto check = [&](int id) {
            if (id == i) return;

            Candidate current = {id, b[id]};

            if (better(current, winner)) {
                winner = current;
            }
        };

        // 票が移動した候補者を確認
        for (int v : a[i]) {
            check(v);
        }

        // 通常時の上位2人も確認
        check(first.id);
        check(second.id);

        cout << winner.id + 1 << endl;

        // 得票数を元に戻す
        b[i] = sz;

        for (int v : a[i]) {
            b[v]--;
        }
    }

    return 0;
}
