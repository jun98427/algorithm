#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define MAX_N   1000
#define INF     1e8+7

using namespace std;

int n, m, a, b;
vector<pair<int, int> > edge[MAX_N+1];

int solve() {
    int dist[MAX_N+1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    dist[a] = 0;
    
    priority_queue<pair<int, int> > que;
    que.push({0, a});

    int ret, cur, d;

    while (!que.empty())
    {
        tie(d, cur) = que.top();
        que.pop();

        d = -d;

        if(dist[cur] != d) continue;

        if(b == cur) {
            ret = dist[cur];
            break;
        }

        for (auto it : edge[cur])
        {
            int next, w;
            tie(next, w) = it;

            if(dist[next] > d + w) {
                dist[next] = d+w;
                que.push({-(d+w), next});
            }
        }
    }
    
    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    int v1, v2, cost;
    while (m--)
    {
        cin >> v1 >> v2 >> cost;
        edge[v1].push_back({v2, cost});
    }
    cin >> a >> b;
    
    int ans = solve();

    cout << ans << "\n";

    return 0;
}