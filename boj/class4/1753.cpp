#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_N   20000
#define INF     (int)1e8+1 

using namespace std;

int n, m, s;

int dist[MAX_N+1];
vector<pair<int, int> > edge[MAX_N+1];

int main() 
{
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> s;

    int from, to, weight;
    while (m--)
    {
        cin >> from >> to >> weight;
        edge[from].push_back({to, weight});
    }

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    
    dist[s] = 0;

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
        for (int i = 0; i < edge[cur].size(); i++)
        {
            tie(next, w) = edge[cur][i];

            if(d+w < dist[next]) 
            {
                dist[next] = d+w;
                que.push({-(d+w), next});    
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}