#include <iostream>

#define MAX_N   1000

using namespace std;

int dp[MAX_N+1];

int Solve(int cur) {
    if(dp[cur] != 0) return dp[cur];

    int ret = 0;

    for(int c : {cur-4, cur-3, cur-1}) {
        ret = Solve(c);
        if(ret % 2 == 0) break;
    }

    dp[cur] = ret + 1;

    return ret+1;
}

int main() {
    int n;
    cin >> n;

    dp[1] = dp[3] = dp[4] = 1;
    dp[2] = 2;

    int ans = Solve(n);
    
    if(ans % 2 == 1) cout << "SK\n";
    else cout << "CY\n";

    return 0;
}