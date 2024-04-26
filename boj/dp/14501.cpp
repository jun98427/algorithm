#include <iostream>

#define MAX_N   15

using namespace std;

int n;
int times[MAX_N+1], values[MAX_N+1]; 
int dp[MAX_N+1];

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> times[i] >> values[i];
    }

    for(int i=1; i<=n; i++) {
        int end = i + times[i] - 1;

        int v = values[i];

        for(int j=end; j<=n; j++) {
            dp[j] = max(dp[i-1] + v, dp[j]);
        }
    }

    int ans = dp[1];
    for(int i=2; i<=n; i++) ans = max(ans, dp[i]);
    
    cout << ans << "\n";

    return 0;
}