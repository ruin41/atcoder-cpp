#include <vector>
#include <iostream>
#include <string>
using namespace std;

// 引数の座標が移動できていいとこか判定する
bool moveCheck(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  int range = board.size();
  if (x < 0 || x >= range || y < 0 || y >= range) {
    return false;
  }

  if (board.at(y).at(x) == '#') {
    return false;
  }

  if (checked.at(y).at(x)) {
    return false;
  }

  // 上記以外はtrueを返す
  return true;
}

// 到達できるかどうか判定する
bool reachGoal(vector<string> &board, vector<vector<bool>> &checked, int x, int y) {
  int range = board.size();


  // ベースケース
  if ((x == range - 1) && (y == range - 1)) {
    return true;
  }

  checked.at(y).at(x) = true;  // 既に調べているという状態に変えておく

  // 移動してゴールに到達できるかフラグ
  bool result = false;

  // 上方向のチェック
  if (moveCheck(board, checked, x, y - 1) && reachGoal(board, checked, x, y - 1)) {
    result = true;
  }
  // 下方向のチェック
  if (moveCheck(board, checked, x, y + 1) && reachGoal(board, checked, x, y + 1)) {
    result = true;
  }
  // 左方向のチェック
  if (moveCheck(board, checked, x - 1, y) && reachGoal(board, checked, x - 1, y)) {
    result = true;
  }
  // 右方向のチェック
  if (moveCheck(board, checked, x + 1, y) && reachGoal(board, checked, x + 1, y)) {
    result = true;
  }

  return result;
}

int main() {
  int range = 0;
  cin >> range;

  // マス目の入力
  vector<string> board(range);
  for(int i = 0; i < range; i++){
    cin >> board.at(i);
  }

  vector<vector<bool>> checked(range, vector<bool>(range, false));
  
  if (reachGoal(board, checked, 0, 0)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }



}
