#include <iostream>
#include <tuple>
#include <vector>

#define MAX_N   2000
#define MAX_M   10000

using namespace std;

int n, c, m;
// n : 마을의 수
// c : 적재 가능한 양
// m : edge 수

int edge[MAX_N+1][MAX_N+1];
int container[MAX_N+1];
int ans;

void travel(int cur) {
    ans += container[cur];

    if(cur == n) {
        return;    
    }

    int to, add, remain = c;
    for (int i = cur+1; i <= n; i++)
    {
        if(remain == 0) container[i] = 0;
        else {
            container[i] = min(remain, container[i]+edge[cur][i]);
            remain -= container[i];
        }
    }

    travel(cur+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c >> m;

    int from, to, weight;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> weight;
        edge[from][to] = weight;
    }

    travel(1);

    cout << ans << endl;

    return 0;
}