#include <iostream>
#include <vector>

#define MAX_N 500

using namespace std;

int n, m;
vector<int> edge[MAX_N+1];
bool is_visited[MAX_N+1];
int parent[MAX_N+1];

bool DFS(int cur) {
    bool ret = true;

    for (int next : edge[cur])
    {
        if(is_visited[next]) {
            if(parent[cur] != next) ret = false;
            continue;
        }

        is_visited[next] = true;
        parent[next] = cur;

        bool re = DFS(next);

        if(!re) ret = false;
    }
    
    return ret;
}

int solve() {
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if(is_visited[i]) continue;

        is_visited[i] = true;
        bool result = DFS(i);
        if(result) ret++;
    }

    return ret;
}

void init() {
    for (int i = 1; i <= n; i++)
    {
        edge[i].clear();
        is_visited[i] = false;
        parent[i] = 0;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int test_case = 0;
    while (true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        test_case++;
        init();

        int n1, n2;

        for (int i = 0; i < m; i++)
        {
            cin >> n1 >> n2;

            edge[n1].push_back(n2);
            edge[n2].push_back(n1);
        }

        int ans = solve();

        if(ans == 0) printf("Case %d: No trees.\n", test_case);
        else if(ans == 1) printf("Case %d: There is one tree.\n", test_case);
        else printf("Case %d: A forest of %d trees.\n", test_case, ans);
    }
    
    return 0;
}