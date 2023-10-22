#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    string str;
    cin >> str;

    unordered_set<string> sets;

    for (int i = 0; i < str.size(); i++)
    {
        for (int j = 1; j <= str.size() - i; j++)
        {
            string tmp = str.substr(i, j);
            sets.insert(tmp);
        }
    }
    
    cout << sets.size() << "\n";

    return 0;
}