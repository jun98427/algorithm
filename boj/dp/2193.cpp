#include <iostream>

#define MAX_N   90

using namespace std;
using ll = long long;

ll dp[MAX_N+1];
int n;

int main() {
    cin >> n;

    dp[1] = dp[2] = 1;

    for(int i=3; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << "\n";

    return 0;
}