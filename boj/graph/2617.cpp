#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_N = 99;

vector<int> l[MAX_N+1], h[MAX_N+1];
bool isv[MAX_N+1];

int n, m;

// n 의 수가 적다 -> n 을 기준으로 무거운 것과 알 수 없는 것, 가벼운 것
// 시간 제한 1초
int bfs(int s, vector<int> e[MAX_N+1]) {
    int ret = 0;
    isv[s] = true;  
    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next : e[cur]) {
            if(!isv[next]) {
                ret++;
                isv[next] = true;
                q.push(next);
            }
        }
    }

    return ret;
}

int main() {
    // freopen("in.txt","r", stdin);

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        l[a].push_back(b);
        h[b].push_back(a);
    }

    int ans = 0, mid = (n-1) / 2;

    for(int i=1; i<=n; i++) {
        memset(isv, false, sizeof(isv));
        int hw = bfs(i, h);
        int lw = bfs(i, l);

        if(hw > mid || lw > mid) ans++;
    }

    cout << ans << "\n";

    return 0;
}