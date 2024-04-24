#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 100'000;
const int MAX_M = 1'000;
const int MAX_K = 1'000;

int isv[MAX_N+1];
// N 의 수가 너무 크다는 단점 존재
int con[MAX_M][MAX_K];
vector<int> inv[MAX_N+1];

int n, m, k;

int solve() {
    int ret = -1;

    isv[1] = 1;
    queue<int> que;
    que.push(1);

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        int d = isv[cur];

        if(cur == n) {
            return d;
        }

        for (int idx : inv[cur])
        {
            for(int i = 0; i<k; i++) {
                int next = con[idx][i];

                if(isv[next] == 0) {
                    isv[next] = d+1;
                    que.push(next);
                }
            }
        }
    }

    return ret;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> k >> m;

    for(int i=0; i<m; i++) {
        for(int j=0; j<k; j++) {
            int v;
            cin >> v;
            con[i][j] = v;
            inv[v].push_back(i);
        }
    }

    int ans = solve();

    cout << ans << "\n";

    return 0;
}