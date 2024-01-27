#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <functional>

#define MAX_V   10000
#define MAX_E   100000

using namespace std;

using ll = long long;

pair<int, int> edge[MAX_E];
int parent[MAX_V+1];

int findParent(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

bool Union(int a, int b) {
    int p1 = findParent(a);
    int p2 = findParent(b);

    if(p1 == p2) return false;

    parent[p1] = p2;

    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int v, e;
    cin >> v >> e;

    int v1, v2, w;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    
    for (int i = 0; i < e; i++)
    {
        cin >> v1 >> v2 >> w;
        edge[i].first = v1;
        edge[i].second = v2;

        que.push({w, i});
    }
    
    for (int i = 1; i <= v; i++)
    {
        parent[i] = i;
    }

    int selec = 0;
    ll ans = 0;
    int idx;
    while (!que.empty())
    {
        tie(w, idx) = que.top();
        que.pop();

        int a, b;
        tie(a, b) = edge[idx];

        if(Union(a, b)) {
            selec++;
            ans += w;
        }

        if(selec == v-1) break;
    }
    
    cout << ans << "\n";

    return 0;
}