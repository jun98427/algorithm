#include <iostream>

#define MAX_N   1'500'000

using namespace std;

int dp[MAX_N+51];

int main() {
    // freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int t,v;
    for(int i=1; i<=n; i++) {
        cin >> t >> v;
        dp[i+t] = max(dp[i+t], dp[i] + v);
        dp[i+1] = max(dp[i], dp[i+1]);
    }

    cout << dp[n+1] << "\n";

    return 0;
}