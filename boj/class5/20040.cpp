#include <iostream>
#include <tuple>

using namespace std;

const int MAX_N = 500'000;
const int MAX_M = 1'000'000;

int parent[MAX_N];
pair<int, int> edge[MAX_M];

int findParent(int x) {
    if(x == parent[x]) return x;

    return parent[x] = findParent(parent[x]);
}

bool Union(int x, int y) {
    int px = findParent(x);
    int py = findParent(y);

    if(px == py) return false;

    parent[px] = py;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);

    int ans = -1;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> edge[i].first >> edge[i].second;        
    }

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int v1, v2;
    for (int i = 0; i < m; i++)
    {
        tie(v1, v2) = edge[i];

        if(!Union(v1, v2)) {
            ans = i;
            break;
        }
    }
    
    cout << ans+1 << "\n";
    
    return 0;
}