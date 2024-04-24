#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_N   100

using namespace std;

int n, s, t, m;
vector<int> edges[MAX_N+1];
bool visited[MAX_N+1];

int Solve() {
    queue<pair<int, int> > que;
    que.push({s, 0});
    visited[s] = true;

    while (!que.empty())
    {
        int cur, d;
        tie(cur, d) = que.front();
        que.pop();

        if(cur == t) return d;

        for(int next : edges[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                que.push({next, d+1});
            }
        }
        
    }
    

    return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> s >> t >> m;
    
    int c, p;
    while (m--)
    {
        cin >> c >> p;
        edges[p].push_back(c);
        edges[c].push_back(p);
    }

    int ans = Solve();

    cout << ans << "\n";
    
    return 0;
}