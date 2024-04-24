#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 10'000;

vector<int> edges[MAX_N+1];
int Counts[MAX_N+1];
bool is_visited[MAX_N+1];

int DFS(int s) {
    is_visited[s] = true;
    int ret = 1;

    for(int next : edges[s]) {
        if(is_visited[next]) continue;
        ret += DFS(next);
    }

    return ret;
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges[b].push_back(a);
    }

    a = 0;

    for(int i = 1; i <= n; i++) {
        memset(is_visited, false, sizeof(is_visited));
        int re = DFS(i);
        Counts[i] = re;
        a = max(a, re);
    }

    for(int i = 1; i <= n; i++ ) {
        if(a == Counts[i]) cout << i << " ";
    }
    cout << "\n";

    return 0;
}