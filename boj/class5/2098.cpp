#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 16;
const int INF = 987654321;

int n;
int costs[MAX_N][MAX_N];
int dp[MAX_N][1 << MAX_N];
int ch;

int DFS(int cur, int vs) {
    if(vs == ch) {
        if(costs[cur][0] == 0) return INF;
        else return costs[cur][0];
    }

    if(dp[cur][vs] != -1) return dp[cur][vs];

    dp[cur][vs] = INF;
    for (int i = 0; i < n; i++)
    {
        if(costs[cur][i] == 0) continue;
        if((vs) & (1 << i)) continue;

        dp[cur][vs] = min(dp[cur][vs], 
            costs[cur][i] + DFS(i, vs | 1 << i));
    }
    
    return dp[cur][vs];
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> costs[i][j];
        }
    }

    ch = (1 << n) - 1;
    memset(dp, -1, sizeof(dp));

    int ans = DFS(0, 1);

    cout << ans << "\n";

    return 0;
}