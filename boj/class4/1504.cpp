#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define MAX_N   800
#define INF     1e8+7

using namespace std;

using ll = long long;

vector<pair<int, int> > edge[MAX_N+1];
int n, m;

void Dijkstra(int s, int dist[MAX_N+1]) {
    priority_queue<pair<int, int> > que;
    que.push({0, s});
    dist[s] = 0;

    int cur, d;
    while (!que.empty())
    {
        tie(d, cur) = que.top();
        que.pop();

        d = -d;
        if(dist[cur] != d) continue;

        for (pair<int, int> n : edge[cur])
        {
            int next, w;
            tie(next, w) = n;

            if(dist[next] > d + w) {
                dist[next] = d+w;
                que.push({-(d+w), next});
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    int a, b, cost;
    while (m--)
    {
        cin >> a >> b >> cost;

        edge[a].push_back({b, cost});
        edge[b].push_back({a, cost});
    }

    int v1, v2;
    cin >> v1 >> v2;

    // v1에서 다익스트라 v2에서 다익스트라 -> 1 -> v1 -> v2 -> n or 1 -> v2 -> v1 -> n
    
    int dist[MAX_N+1], dist2[MAX_N+1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = dist2[i] = INF;
    }

    Dijkstra(v1, dist);
    Dijkstra(v2, dist2);

    ll d1 = dist[1] + dist[v2] + dist2[n];
    ll d2 = dist2[1] + dist2[v1] + dist[n];

    ll ans = min(d1, d2);
    if(ans >= INF) ans = -1;

    cout << ans << "\n";

    return 0;
}