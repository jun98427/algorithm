#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

const int MAX_K = 1'000'000;

int main() {
    // freopen("in.txt","r", stdin);
    int tc;
    cin >> tc;

    while (tc--)
    {
        int k;
        cin >> k;
        
        priority_queue<ll> que;
        ll ans = 0;
        
        for(int i=0; i<k; i++) {
            int v;
            cin >> v;
            que.push(-v);
        }

        while (que.size() >= 2) 
        {
            ll temp = 0;
            temp -= que.top();
            que.pop();
            temp -= que.top();
            que.pop();

            ans += temp;
            que.push(-temp);
        }

        cout << ans << "\n";
    }

    return 0;
}