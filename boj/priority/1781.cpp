#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_N = 200'000;

int parent[MAX_N+1];

int findParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

void Union(int a, int b) {
    int p1 = findParent(a);
    int p2 = findParent(b);

    if(p1 == p2) return ;

    parent[p2] = p1;
} 

int main() {
    // freopen("in.txt","r", stdin);
    int n;
    cin >> n;

    priority_queue<pair<int, int> > pq;

    for(int i=1; i<=n; i++) {
        int t, k;
        cin >> t >> k;
        pq.push({k, t});
        parent[i] = i;
    }

    int ans = 0;

    while (!pq.empty())
    {
        int k, t;
        tie(k, t) = pq.top();
        pq.pop();

        int p = findParent(t);

        // cout << "c : " << k << " t : " << t << " p : " << p << "\n";
        
        if(p == 0) continue; 

        ans += k;
        Union(p-1, p);
    }
    
    cout << ans << "\n";

    return 0;
}
