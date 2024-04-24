#include <iostream>
#include <string>
#include <queue>
#include <tuple>

#define MAX_NM  1000
#define MAX_K   10
#define DIR     4

using namespace std;

int n, m, k;
int board[MAX_NM][MAX_NM];
int visited[MAX_K+1][MAX_NM][MAX_NM];

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

int Solve() {
    queue<tuple<int, int, int> > que;
    que.push({0, 0, 0});
    visited[0][0][0] = 1;

    int r, c, ck;
    while (!que.empty())
    {
        tie(r, c, ck) = que.front();
        que.pop();

        int d = visited[ck][r][c];
        if(r == n-1 && c == m-1) return d;

        for(int i=0; i<DIR; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc)) continue;
            
            int nk = ck + board[nr][nc];

            if(nk > k || visited[nk][nr][nc] != 0) continue;

            visited[nk][nr][nc] = d+1;
            que.push({nr, nc, nk});
        }
    }
    
    return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> m >> k;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j<m; j++) board[i][j] = str[j] - '0';
    }

    int ans = Solve();

    cout << ans << "\n";

    return 0;
}