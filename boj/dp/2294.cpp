#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_K   100'000

using namespace std;

vector<int> coins;
int n, k;
int dp[MAX_K+1];

int Solve(int remain) {
    if(remain == 0 || dp[remain] != 0) return dp[remain];

    int ret = -1;

    for(int i=n-1; i>=0; i--) {
        if(remain - coins[i] < 0) continue;

        int re = Solve(remain - coins[i]);

        if(re == -1) continue;

        if(ret == -1 || ret > re + 1) {
            ret = re+1;
        } 
    }

    dp[remain] = ret;

    return ret;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> k;
    
    int c;
    for(int i=0; i<n; i++) {
        cin >> c;
        coins.push_back(c);
        dp[c] = 1;
    }

    sort(coins.begin(), coins.end());

    int ans = Solve(k);

    cout << ans << "\n";

    return 0;
}