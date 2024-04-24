#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 20'000;
vector<int> edges[MAX_N+1];
int Dist[MAX_N+1];

int main() {
    // freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    memset(Dist+2, -1, sizeof(int) * (n-1));

    queue<int> que;
    que.push(1);

    int max_dist = 0;

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        int d = Dist[cur];
        max_dist = d;

        for(int next : edges[cur]) {
            if(Dist[next] == -1) {
                Dist[next] = d+1;
                que.push(next);
            }
        }
    }
    
    int loc = -1, num_of_loc = 0;

    for(int i = 1; i<=n; i++) {
        if(max_dist == Dist[i]) {
            if(loc == -1) loc = i;
            num_of_loc++;
        }
    }

    printf("%d %d %d\n", loc, max_dist, num_of_loc);

    return 0;
}