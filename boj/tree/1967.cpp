#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>

#define MAX_N 10000

using namespace std;

int dist[MAX_N+1];
bool is_visited[MAX_N+1];
vector<pair<int, int> > edge[MAX_N+1];

int n;

void DFS(int cur) {
    int next, distance;
    for (pair<int, int> it : edge[cur])
    {
        tie(next, distance) = it;

        if(is_visited[next]) continue;
        
        is_visited[next] = true;
        dist[next] = dist[cur] + distance;
        DFS(next);
    }
} 

int main() {
    cin >> n;

    int parent, child, distance;
    for (int i = 0; i < n-1; i++)
    {
        cin >> parent >> child >> distance;
        edge[parent].push_back({child, distance});
        edge[child].push_back({parent, distance});
    }

    is_visited[1] = true;
    DFS(1);

    int max_dist = dist[1];
    int r_idx = 1;
    for (int i = 1; i <= n; i++)
    {
        if(dist[i] > max_dist) {
            max_dist = dist[i];
            r_idx = i;
        }

        is_visited[i] = false;
    }

    dist[r_idx] = 0;
    is_visited[r_idx] = true;
    DFS(r_idx);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }
    
    cout << ans << endl;

    return 0;
}