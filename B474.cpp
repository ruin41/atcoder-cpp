#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num = 0;
    cin >> num;

    int groupNum = (num + 9) / 10;

    vector<vector<int>> group(groupNum);

    // 人数分の番号を入力
    for (int i = 0; i < num; i++) {
        int one = 0;
        cin >> one;

        group[i / 10].push_back(one);
    }

    bool isBleach = false;

    // 各グループの番号を判定
    for (int i = 0; i < groupNum; i++) {
        for (int one : group[i]) {
            int a = (one - 1) / 10;

            if (a != i) {
                isBleach = true;
                break;
            }
        }

        if (isBleach) {
            break;
        }
    }

    cout << (isBleach ? "No" : "Yes") << endl;

    return 0;
}