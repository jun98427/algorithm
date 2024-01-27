#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_N   1000
#define INF     (int)1e8+1 

using namespace std;

int n, m, s;

vector<pair<int, int> > edge[MAX_N+1], r_edge[MAX_N+1];

void dijkstra(vector<pair<int, int> > e[MAX_N+1], int dist[MAX_N+1]) {
    priority_queue<pair<int, int> > que;
    que.push({0, s});

    int cur, d;
    while (!que.empty())
    {
        tie(d, cur) = que.top();
        que.pop();

        d = -d;
        if(dist[cur] != d) continue;
        
        int next, w;
        for (int i = 0; i < e[cur].size(); i++)
        {
            tie(next, w) = e[cur][i];

            if(dist[next] > d+w) 
            {
                dist[next] = d+w;
                que.push({-(d+w), next});
            }
        }
    }
}

int main() 
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> s;

    int from, to, weight;
    while (m--)
    {
        cin >> from >> to >> weight;
        edge[from].push_back({to, weight});
        r_edge[to].push_back({from, weight});
    }

    int dist[MAX_N+1];
    int r_dist[MAX_N+1];

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        r_dist[i] = INF;
    }
    
    dist[s] = 0;
    r_dist[s] = 0;

    dijkstra(edge, dist);
    dijkstra(r_edge, r_dist);
    
    int ans = dist[1] + r_dist[1];
    for (int i = 2; i <= n; i++)
    {
        ans = max(ans, dist[i] + r_dist[i]);
    }

    cout << ans << "\n";

    return 0;
}