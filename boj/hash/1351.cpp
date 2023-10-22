#include <iostream>
#include <map>

using namespace std;
using ll = long long;

ll N, P, Q;
map<ll, ll> mapper;

ll DFS(ll val) {
    if(mapper.find(val) != mapper.end()) return mapper[val];

    ll left = DFS(val / P);
    ll right = DFS(val / Q);

    mapper[val] = left+right;

    return left+right;
}

int main() {
    cin >> N >> P >> Q;

    mapper[0] = 1;

    ll ans = DFS(N);

    cout << ans << endl;

    return 0;
}