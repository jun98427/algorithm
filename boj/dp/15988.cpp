#include <iostream>

#define MAX_N   1'000'000
#define DIV     1'000'000'009

using namespace std;
using ll = long long;

ll dp[MAX_N+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    int n, prev = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    while (tc--)
    {
        cin >> n;
        for(int i=max(4, prev+1); i<=n; i++) {
            ll temp = dp[i-3] + dp[i-2] +dp[i-1];
            dp[i] = temp % DIV;   
        }

        cout << dp[n] << "\n";
        prev = n;
    }
    
    return 0;
}