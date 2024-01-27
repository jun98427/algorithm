#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

using ll = long long;

int main() {
    // freopen("input.txt", "r", stdin);

    int a, b, ans = -1;
    cin >> a >> b;

    queue<pair<ll, int> > que;
    que.push({a, 1});

    ll cur;
    int cnt;
    while (!que.empty())
    {
        tie(cur, cnt) = que.front();
        que.pop();

        // cout << "cur : " << cur << " cnt : " << cnt << "\n";

        if(cur == b) {
            ans = cnt;
            break;
        }

        if(cur > b) continue;

        que.push({cur << 1, cnt+1});
        que.push({cur*10+1, cnt+1});
    }
    
    cout << ans << "\n";

    return 0;
}