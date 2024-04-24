#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 500;
vector<int> edges[MAX_N+1];
bool is_invite[MAX_N+1];

int main() {
    // freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    int a, b;
    while (m--)
    {
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    is_invite[1] = true;
    int ans = 0;

    for(int f : edges[1]) {
        if(!is_invite[f]) {
            is_invite[f] = true;
            ans++;
        }

        for(int n : edges[f]) {
            if(!is_invite[n]) {
                ans++;
                is_invite[n] = true;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

