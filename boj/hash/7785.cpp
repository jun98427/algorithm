#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string name, cmd;

    set<string> sets;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> cmd;

        if(cmd == "enter") {
            sets.insert(name);
        }else {
            sets.erase(name);
        }
    }

    for (auto it = sets.rbegin(); it != sets.rend(); it++)
    {
        cout << *it << "\n";
    }

    return 0;
}