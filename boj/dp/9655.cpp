#include <iostream>

#define MAX_N   1'000

using namespace std;

int dp[MAX_N+1];

int main() {
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;

    for(int i=4; i<= n; i++) {
        dp[i] = min(dp[i-1], dp[i-3]) + 1;
    }

    if(dp[n] % 2 == 1) cout << "SK\n";
    else cout << "CY\n";

    return 0;
}