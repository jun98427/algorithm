#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

using ll = long long;

const int MAX_N = 100;
const int MAX_S = 10000;
int ans = 1e9+7;

// cost, mem
pair<int, int> info[MAX_N+1];
ll dp[MAX_N+1][MAX_S+5];
// cost 0 ~ 100
// n    1 ~ 100
// dp 를 cost로 돌리면 가능할 듯


int main() {
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> info[i].second;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> info[i].first;
    }
    
    sort(info+1, info+n+1);

    int cost, mem;
    for (int i = 1; i <= n; i++)
    {
        tie(cost, mem) = info[i];
        for (int j = 0; j <= MAX_S; j++)
        {
            if(j < cost) {
                dp[i][j] = dp[i-1][j];
                continue;
            }

            dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost] + mem);
        }
    }

    int ans = -1;

    for (int i = 0; i <= MAX_S; i++)
    {
        if(dp[n][i] >= m) {
            ans = i;
            break;
        }
    }
    
    cout << ans << "\n";

    return 0;
}