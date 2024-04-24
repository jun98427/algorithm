#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;
using ll = long long;

const int MAX_N = 100'000;

int main() {
    // freopen("in.txt","r", stdin);
    int n;
    cin >> n;
    
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i=0; i<n; i++) {
        int v;
        cin >> v;
        pq.push(v);
    }

    ll ans = 0;
    while (pq.size() >= 2)
    {
        int v1, v2;
        v1 = pq.top(); pq.pop();
        v2 = pq.top(); pq.pop();
        
        ll temp = v1 + v2;
        ans += temp;
        pq.push(temp);
    }

    cout << ans << "\n";
    
    return 0;
}