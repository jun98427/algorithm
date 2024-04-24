#include <iostream>

using namespace std;

const int MAX_N = 1000;
const int INF = 1e8+7;
const int COLOR_N = 3;

int cost[MAX_N+1][3];
int dp[MAX_N+1][3];
int n, ans;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    ans = INF;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(i == j) dp[1][i] = cost[1][i];
            else dp[1][j] = INF;
        }

        for(int j=2;j<=n;j++){
            dp[j][0] = min(dp[j-1][1],dp[j-1][2])+cost[j][0];
            dp[j][1] = min(dp[j-1][0],dp[j-1][2])+cost[j][1];
            dp[j][2] = min(dp[j-1][1],dp[j-1][0])+cost[j][2];
        }

        for(int j=0;j<=2;j++){
            if(j == i) continue;
            ans = min(ans, dp[n][j]);
        }
    }

    
    cout << ans << "\n";

    return 0;
}