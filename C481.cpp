#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator> 
#include <map>
using namespace std;

int main() {
    int Q = 0;
    cin >> Q;

    map<string, int> bank;

    int id = 1;
    for (int i = 0; i < Q; i++) {
        string name = "";
        cin >> name;

        if (bank.find(name) == bank.end()) {
            bank[name] = id;
            id++;
        }
        cout << bank[name] << endl;
    }
}