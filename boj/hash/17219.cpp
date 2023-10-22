#include <iostream>
#include <string>
#include <map>

using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    cin >> n >> m;

    string site, pw;
    map<string, string> mapper;
    for (int i = 0; i < n; i++)
    {
        cin >> site >> pw;
        mapper[site] = pw;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> site;
        cout << mapper[site] << "\n";
    }

    return 0;
}