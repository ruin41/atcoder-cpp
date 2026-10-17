#include <iostream>
#include <string>

using namespace std;

int main() {
    string input = "";
    // 英小文字の入力
    cin >> input;
    // 英小文字の文字列の長さの取得
    //int size = input.size();

    // 英小文字の末尾がeの場合、rを追加
    if (input.back() == 'e'){
    //if (input[size - 1] == 'e') {
        input += "r";
    }
    // 英小文字の末尾がeでない場合、erを追加
    else {
        input += "er";
    }

    // inputの出力
    cout << input << endl;
}