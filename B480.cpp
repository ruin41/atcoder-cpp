#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

auto checkName = [](string A, string B) -> bool {
    // 文字数が異なる場合、falseを返す。
    if (A.size() != B.size()) {
        return false;
    }

    // 一文字ずつ比較する。
    int notMatchCount = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) notMatchCount++;
        // 二文字以上違う場合、falseを返す。
        if (notMatchCount >= 2) {
            return false;
        }
    }
    // 名前一致としてtrueを返す。
    return true;
};


int main() {
    // 候補者数の入力
    int N = 0;
    cin >> N;

    vector<string> candidates(N);
    map<string, int> voteCounts;

    // 投票数の入力
    int M = 0;
    cin >> M;
    vector<string> voteResults(M);

    for (string& person : candidates) {
        cin >> person;
    }

    for (string& vote : voteResults) {
        cin >> vote;
    }

    for (int i = 0; i < M; i++) {
        int VoteCnt = 0;
        bool isMatch = false;
        string voteName = "";
        for (const string& name : candidates) {
            // 完全一致の場合、処理を抜ける。
            if (name == voteResults[i]) {
                voteName = name;
                isMatch = true;
                break;
            }
            // 一文字違いで、名前が一致しているか判定する。
            // 一致してる場合、名前を取得し、投票カウントを1加算する。
            if (checkName(voteResults[i], name)) {
                voteName = name;
                VoteCnt++;
            }
        }
        // 完全一致、または投票対象が一人の場合、カウントする。
        if ((VoteCnt == 1) || (isMatch)) {
            voteCounts[voteName] += 1;
        }
    }
    for (string name : candidates) {
        cout << voteCounts[name] << endl;
    }
}