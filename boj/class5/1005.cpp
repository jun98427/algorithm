#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

const int MAX_N = 1000;
int costs[MAX_N+1];
int income[MAX_N+1];
ll dp[MAX_N+1];

vector<int> edges[MAX_N+1];

int main() {
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;

    while (tc--)
    {
        int n, k, w;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            cin >> costs[i];
            dp[i] = 0;
            income[i] = 0;
            edges[i].clear();
        }

        int frm, to;
        for (int i = 0; i < k; i++)
        {
            cin >> frm >> to;
            income[to]++;
            edges[frm].push_back(to);
        }
        cin >> w;

        queue<int> que;

        for (int i = 1; i <= n; i++)
        {
            if(income[i] == 0) que.push(i);
        }

        ll ans = -1;
        while (!que.empty())
        {
            int cur = que.front();
            que.pop();

            dp[cur] += costs[cur];

            // cout << "cur : " << cur << " " << dp[cur] << "\n";

            if(cur == w) 
            { 
                ans = dp[cur];
                break;
            }

            for (int next : edges[cur])
            {
                dp[next] = max(dp[next], dp[cur]);
                income[next]--;

                if(income[next] == 0) que.push(next);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}