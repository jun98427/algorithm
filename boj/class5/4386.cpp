#include <iostream>
#include <cmath>
#include <tuple>
#include <queue>

using namespace std;

const int MAX_N = 100;

pair<double, double> points[MAX_N+1];
int parent[MAX_N+1];

int findParent(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}

bool Union(int v1, int v2) {
    int p1 = findParent(v1);
    int p2 = findParent(v2);

    if(p1 == p2) return false;

    parent[p2] = p1;
    return true;
}


int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    priority_queue<tuple<double, int, int> > que;

    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cin >> x >> y;

        parent[i] = i;
        points[i] = {x, y};

        for (int j = 1; j < i; j++)
        {
            double x_diff = x - points[j].first;
            double y_diff = y - points[j].second;

            double dist = sqrt(x_diff * x_diff + y_diff * y_diff);

            que.push({-dist, i, j});
        }
    }

    double ans = 0;
    int cnt = 0;

    while (!que.empty())
    {
        double d;
        int v1, v2;
        tie(d, v1, v2) = que.top();
        que.pop();
        // cout << "v1 " << v1 << " v2 " << v2 << " " << -d << "\n";

        if(Union(v1, v2)) {
            ans -= d;
            cnt++;
        }

        if(cnt == n-1) break;
    }
    
    cout << fixed;
    cout.precision(2);
    cout << ans << "\n";

    return 0;
}