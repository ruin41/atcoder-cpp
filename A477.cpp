#include <iostream>

using namespace std;

int main() {
    char now;
    while(true) {
        cin >> now;
        if (now == 'B') {
            cout << "Y" << endl;
            break;
        }
        else if (now == 'Y') {
            cout << 'R' << endl;
            break;
        }
        else if (now == 'R') {
            cout << 'B' << endl;
            break;
        }
        else {
            cout << "B, Y, Rのいずれかを入力してください";
            continue;
        }
    }
}