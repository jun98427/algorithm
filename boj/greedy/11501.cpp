#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

int T, n;

void solve(){
    cin >> n;

    int cnt = 0;
    long long ans = 0;
    int v;
    stack<pair<int, int> > s;

    for (int i = 0; i < n; i++)
    {
        cin >> v;

        if(s.empty()){
            s.push({v, 1});
            continue;
        }else {
            int cnt = 0;
            while (!s.empty())
            {
                if(s.top().first >= v) break;

                cnt += s.top().second;
                ans += (v - s.top().first) * s.top().second;
                s.pop();
            }
            s.push({v, cnt+1});
        }
    }

    cout << ans << endl;
}


int main() {
    // freopen("input.txt", "r", stdin);
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}