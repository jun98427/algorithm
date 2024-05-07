#include <iostream>
#include <cstring>

#define MAX_N   20
#define MAX_M   10'000

using namespace std;

int coins[MAX_N];
int dp[MAX_M+1][MAX_N];
int n, m;

int Solve(int t, int idx) {
    if(dp[t][idx] != -1) return dp[t][idx];
    if(t == 0) return 1;
    
    if(idx == 0) {
        int ret = ((t % coins[0]) == 0 ? 1 : 0);
        dp[t][0] = ret;
        return ret;
    }

    int div = t / coins[idx];
    
    int ret = 0;
    for(int i=div; i>= 0; i--) {
        int remain = t - coins[idx] * i;
        ret += Solve(remain, idx-1);
    }

    dp[t][idx] = ret;
    return ret;
}

int main() {
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> n;
        for(int i=0; i<n; i++) cin >> coins[i];

        cin >> m;
        memset(dp, -1, sizeof(dp));

        int ans = Solve(m, n-1);

        cout << ans << "\n";
    }
    
    return 0;
}