#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

int n, k;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> k >> n;

    map<string, int> mapper;

    string num;
    int back = n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mapper[num] = i;
    }

    vector<pair<int, string> > v;
    for (auto it : mapper)
    {
        v.push_back(make_pair(it.second, it.first));
    }
    
    sort(v.begin(), v.end());

    for (int i = 0; i < min(k, (int)v.size()); i++)
    {
        cout << v[i].second << "\n";
    }

    return 0;
}