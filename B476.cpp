#include <iostream>
#include <string>
using namespace std;

int main() {
    int num = 0;
    string word = "";
    string serchWord = "";
    cin >> num >> word >> serchWord;

    bool fMatch = true;
    for (int i = 0; i < num; i++) {
        if (serchWord[i] == '*') {
            continue;
        }
        if (word[i] != serchWord[i]) {
            fMatch = false;
            break;
        }
    }
    if (fMatch) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}