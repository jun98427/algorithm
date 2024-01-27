#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring>

#define MAX_N   100
#define INF     10001

using namespace std;

int items[MAX_N+1], dist[MAX_N+1];
vector<pair<int, int> > edge[MAX_N+1];
int n, m, r; // n : 지점의 수   m : 수색 범위   r : 길의 수
int ans = -1;

void dijkstra(int s) {
    // cout << "s : " << s <<"\n"; 
    memset(dist, -1, sizeof(dist));

    dist[s] = 0;
    int cnt = 0;

    priority_queue<pair<int, int> > que;
    que.push({0, s});

    int cur, d;
    while (!que.empty())
    {
        tie(d, cur) = que.top();
        que.pop();

        d = -d;
        if(d > m) break;

        if(dist[cur] != d) continue;

        cnt += items[cur];

        for (pair<int, int> it : edge[cur])
        {
            int next, w;
            tie(next, w) = it;

            if(dist[next] == -1 || dist[next] > d+w) {
                dist[next] = d+w;
                que.push({-(d+w), next});
            }
        }
    }
    
    ans = max(ans, cnt);   
}   

int main() {
    // freopen("input.txt", "r", stdin);
    
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> items[i];
    }

    int v1, v2, w;
    for (int i = 0; i < r; i++)
    {
        cin >> v1 >> v2 >> w;
        edge[v1].push_back({v2, w});
        edge[v2].push_back({v1, w});
    }

    // 다익스트라를 n 번 진행?
    // O(VElogV) e -> 100 v -> 100 가능할 듯

    for (int i = 1; i <= n; i++)
    {
        dijkstra(i);
    }
    
    cout << ans << "\n";

    return 0;
}