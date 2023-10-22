#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int n, m;
    set<string> sets, ans;
    cin >> n >> m;

    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        sets.insert(str);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if(sets.find(str) != sets.end()) ans.insert(str);
    }
    
    cout << ans.size() << endl;
    for (string it : ans)
    {
        cout << it << "\n";
    }
    
    return 0;
}