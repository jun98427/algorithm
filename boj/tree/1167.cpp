#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 100000

using namespace std;

int dist[MAX_N+1];
bool is_visited[MAX_N+1];
vector<pair<int, int> > edge[MAX_N+1];

int n;

void DFS(int cur) {
    int next, d;
    for (pair<int, int> it : edge[cur])
    {
        tie(next, d) = it;

        if(is_visited[next]) continue;

        is_visited[next] = true;
        dist[next] = dist[cur] + d;

        DFS(next);
    }
}

int main() {
    cin >> n;

    int cur, next, distance;

    for (int i = 0; i < n; i++)
    {
        cin >> cur;

        while (true)
        {
            cin >> next;
            if(next == -1) break;

            cin >> distance;
            edge[cur].push_back({next, distance});
        }
    }
    
    is_visited[1] = true;
    DFS(1);
    
    int max_dist = 0;
    int idx = 0;

    for (int i = 1; i <= n; i++)
    {
        if(dist[i] > max_dist) {
            idx = i;
            max_dist = dist[i];
        }

        is_visited[i] = false;
    }

    is_visited[idx] = true;
    dist[idx] = 0;

    DFS(idx);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }
    
    cout << ans << "\n";

    return 0;
}