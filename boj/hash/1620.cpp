#include <iostream>
#include <string>
#include <map>
#include <cctype>

#define MAX_N   100000

using namespace std;

int n, m;

map<string, int> mapper;
string arr[MAX_N+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mapper[arr[i]] = i;
    }

    string cmd;
    while (m--)
    {
        cin >> cmd;

        if(isupper(cmd[0]) || isupper(cmd[cmd.size()-1])) {
            cout << mapper[cmd] << "\n";
        }else {
            int idx = stoi(cmd);
            cout << arr[idx] << "\n";
        }
    }

    return 0;
}
