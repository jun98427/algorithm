#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
map<string, string> team_mapper;
map<string, int> member_mapper;
vector<string> arr[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // freopen("input.txt", "r" , stdin);
    cin >> n >> m;

    int cnt;
    string team;
    for (int i = 0; i < n; i++)
    {
        cin >> team >> cnt;
        member_mapper[team] = i;

        for (int j = 0; j < cnt; j++)
        {
            string name;
            cin >> name;
            team_mapper[name] = team;
            arr[i].push_back(name);
        }

        sort(arr[i].begin(), arr[i].end());
    }

    int cmd;
    string name;
    while (m--)
    {
        cin >> name >> cmd;

        if(cmd == 1) {
            cout << team_mapper[name] << "\n";
        }else {
            int idx = member_mapper[name];
            for (string s : arr[idx])
            {
                cout << s << "\n";
            }
        }
    }
    
    return 0;
}