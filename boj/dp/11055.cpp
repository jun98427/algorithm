#include <iostream>

#define MAX_N   1000

using namespace std;

int n, arr[MAX_N], dp[MAX_N];

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n;

    for(int i=0; i<n; i++) cin >> arr[i];
    
    dp[0] = arr[0];

    for(int i=1; i<n; i++) {
        int c = arr[i];
        dp[i] = c;
        
        for(int j=0; j<i; j++) {
            if(c > arr[j]) {
                dp[i] = max(dp[i], c + dp[j]);
            }
        }
    }

    int ans = dp[0];
    for(int i=1; i<n; i++) ans = max(ans, dp[i]);

    cout << ans << "\n";

    return 0;
}