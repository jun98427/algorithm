#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 1000
#define MAX_H 30

using namespace std;

vector<pair<int, int> > edge[MAX_N+1];
bool is_visited[MAX_N+1];
int parent[MAX_H][MAX_N+1];
int dist[MAX_N+1];
int depth[MAX_N+1];

int n, m;

void DFS(int cur) {

    int next, d;
    for(auto it : edge[cur])
    {
        tie(next, d) = it;
        
        if(is_visited[next]) continue;

        is_visited[next] = true;
        dist[next] = dist[cur] + d;
        depth[next] = depth[cur] + 1;
        parent[0][next] = cur;
        
        DFS(next);
    }
}

int get_parent(int a, int b) {
    if(depth[a] < depth[b]) {
        int t = a;
        a = b;
        b = t;
    }

    for (int i = MAX_H-1; i >= 0; i--)
    {
        if(depth[a] - depth[b] >= (1 << i)) {
            a = parent[i][a];
        }
    }
    
    if(a == b) return a;

    for (int i = MAX_H-1; i >= 0; i--)
    {
        if(parent[i][a] != parent[i][b]) {
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    
    return parent[0][a];
}

int main() {
    // freopen("input.txt", "r" , stdin);
    cin >> n >> m;

    int n1, n2, d;
    for (int i = 0; i < n-1; i++)
    {
        cin >> n1 >> n2 >> d;

        edge[n1].push_back({n2, d});
        edge[n2].push_back({n1, d});
    }

    is_visited[1] = true;
    depth[1] = 1;
    DFS(1);
    
    for (int h = 1; h < MAX_H; h++)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[h][i] = parent[h-1][parent[h-1][i]];
        }
    }

    while (m--)
    {
        cin >> n1 >> n2;

        int p = get_parent(n1, n2);
        // cout << "p : " << p << "\n";

        cout << dist[n1] + dist[n2] - dist[p] * 2 << "\n";
    }

    return 0;
}