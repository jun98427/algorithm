#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

using ll = long long;

ll ans;
vector<int> edge[MAX_N+1];
bool is_visited[MAX_N+1];

int n, m;

void DFS(int cur, int p) {
    for (int next : edge[cur])
    {
        if(is_visited[next]) {
            continue;
        }

        is_visited[next] = true;
        DFS(next, cur);
    }
}

void solve() {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if(!is_visited[i]) {
            cnt++;
            is_visited[i] = true;
            DFS(i, 0);
        }
    }
        
    ans = 2*cnt + m - n - 1;
}


int main() {
    cin >> n >> m;

    int n1, n2;
    for (int i = 0; i < m; i++)
    {
        cin >> n1 >> n2;

        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }

    solve();
    cout << ans << "\n";
    
    return 0;
}