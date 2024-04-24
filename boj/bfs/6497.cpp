#include <iostream>
#include <queue>
#include <tuple>

#define MAX_N   200'000

using namespace std;

int parent[MAX_N];

int FindParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = FindParent(parent[x]);
}

bool Union(int x1, int x2) {
    int p1 = FindParent(x1);
    int p2 = FindParent(x2);

    if(p1 == p2)
        return false;

    parent[p2] = p1;

    return true;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int n, m;

    while (true)
    {
        cin >> m >> n;

        if(n == 0 && m == 0) {
            break;
        }

        for(int i=0; i<m; i++) parent[i] = i;

        int sum = 0;
        int t1, t2, d;

        priority_queue<tuple<int, int, int> > pq;
        for(int i=0; i<n; i++) {
            cin >> t1 >> t2 >> d;
            sum += d;
            pq.push({-d, t1, t2});
        }

        int idx = 0;

        while (true)
        {
            if(idx == m-1) break;

            tie(d, t1, t2) = pq.top();
            pq.pop();

            if(Union(t1, t2)) {
                idx++;
                sum += d;
            }
        }
        
        cout << sum << "\n";
    }

    return 0;
}