#include <iostream>
#include <set>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    int val;

    set<int> sets;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        sets.insert(val);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        sets.erase(val);
    }
    
    cout << sets.size() << "\n";
    for (int it : sets)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}