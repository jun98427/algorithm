#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>

#define MAX_N   1000
#define INF     1e9+7

using namespace std;
using ll = long long;

vector<pair<int, int> > edge[MAX_N+1];
ll dist[MAX_N+1];
int prevs[MAX_N+1];

void Dijkstra(int start, int end) {
    // memset(dist, -1, sizeof(dist));
    dist[start] = 0;

    priority_queue<pair<int, int> > que;
    que.push({0, start});

    int cur, d;
    while (!que.empty())
    {
        tie(d, cur) = que.top();
        que.pop();

        d = -d;
        if(dist[cur] != d) continue;

        // if(d == end) break;

        for (pair<int, int> e : edge[cur])
        {
            int next, w;
            tie(next, w) = e;

            if(d+w < dist[next]) {
                dist[next] = d+w;
                prevs[next] = cur;
                que.push({-(d+w), next});
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin); 
    int n, m, a, b, w;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> w;
        edge[a].push_back({b, w});
    }

    cin >> a >> b;

    fill(dist+1, dist+n+1, INF);

    Dijkstra(a, b);

    vector<int> routes;
    
    int cur = b;
    routes.push_back(cur);
    while (cur != a)
    {
        cur = prevs[cur];
        routes.push_back(cur);
    }

    int l = (int)routes.size();
    cout << dist[b] << "\n" << l << "\n";
    
    for (int i = l-1; i>=0; i--)
    {
        cout << routes[i] << " ";
    }
    cout << "\n";

    return 0;
}