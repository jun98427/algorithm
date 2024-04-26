#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N   1'000'000

using namespace std;

int depth[MAX_N+1];
int n, m;

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;

    if(n == 0) {
        cout << "0\n";
        return 0;
    }

    memset(depth, -1, sizeof(int) * (n+1));

    queue<int> q;
    int v;
    for(int i=0; i<m; i++) {
        cin >> v;
        q.push(v);
        depth[v] = 0;
    }

    int cnt = 0, tmp = n;
    while (tmp)
    {
        cnt++;
        tmp >>= 1;
    }
    
    // cout << cnt << "\n";
    int ans = 0;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int v = depth[cur];

        ans = max(ans, v);

        for(int i=0; i<cnt; i++) {
            tmp = (cur ^ (0x01 << i));

            if(tmp <= n && tmp >= 0) {
                if(depth[tmp] == -1) {
                    depth[tmp] = v+1;
                    q.push(tmp);
                }
            }
        }        
    }
    
    cout << ans << "\n";

    return 0;
}