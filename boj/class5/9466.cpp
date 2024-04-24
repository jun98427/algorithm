#include <iostream>

using namespace std;

const int MAX_N = 100'000;

int to[MAX_N+1];
bool is_visited[MAX_N+1];
bool is_finished[MAX_N+1];
int depth[MAX_N+1];

int DFS(int cur, int dep) {
    is_visited[cur] = true;

    int next = to[cur];
    if(is_finished[next]) {
        is_finished[cur] = true;
        return 0;
    }else if(is_visited[next]){
        is_finished[cur] = true;
        return dep - depth[next] + 1;
    }

    depth[cur] = dep;

    int ret = DFS(next, dep+1);

    is_finished[cur] = true;
    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> to[i];

            if(to[i] == i) {
                is_visited[i] = true;
                is_finished[i] = true;
                cnt++;
            }else{
                is_visited[i] = false;
                is_finished[i] = false;
                depth[i] = 0;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if(!is_visited[i]) cnt += DFS(i, 0);
        }
        
        cout << n - cnt << "\n";
    }
    
    return 0;
}