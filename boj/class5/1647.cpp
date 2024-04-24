#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_N = 100'000;
const int MAX_M = 1'000'000;

int n, m;
pair<int, int> road[MAX_M];
int parent[MAX_N+1];

int findParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

bool Union(int a, int b) {
    int pa = findParent(a);
    int pb = findParent(b);

    if(pa == pb) return false;

    parent[pb] = pa;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    int a, b, cost;

    priority_queue<pair<int, int> >que;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> cost;
        road[i] = {a, b};
        que.push({-cost, i});
    }

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int cnt = 0, ans = 0, idx;

    while (!que.empty())
    {
        if(cnt == n-2) break;

        tie(cost, idx) = que.top();
        que.pop();

        tie(a, b) = road[idx];

        if(!Union(a, b)) continue;

        cnt++;
        ans -= cost;
    }
    
    cout << ans << "\n";

    return 0;
}