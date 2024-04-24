#include <iostream>
#include <queue>
#include <tuple>

#define MAX_RC  1000
#define DIR     4

using namespace std;

char board[MAX_RC][MAX_RC];
int is_visited[MAX_RC][MAX_RC];

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

int n, m;

queue<tuple<int, int, int> > loc;

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && board[r][c] != '#';
}

int solve() {
    int ret = -1;

    int cr, cc, v;
    while (!loc.empty())
    {
        tie(cr, cc, v) = loc.front();
        loc.pop();

        if(v != is_visited[cr][cc]) continue;

        if(cr == 0 || cr == n-1 || cc == 0 || cc == m-1) {
            if(v > 0) return v;
        }

        int nv = (v > 0 ? v+1 : v-1);

        for(int i=0; i<DIR; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(!isIn(nr, nc) || is_visited[nr][nc] < 0) continue;
            
            if(is_visited[nr][nc] != 0) {
                if(nv > 0 || is_visited[nr][nc] != -nv) continue;
            }

            is_visited[nr][nc] = nv;
            loc.push({nr, nc, nv});
        }
    }
    
    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> board[i][j];

            if(board[i][j] == 'J') {
                loc.push({i, j, 1});
                is_visited[i][j] = 1;
            }else if(board[i][j] == 'F') {
                loc.push({i, j, -1});
                is_visited[i][j] = -1;
            }
        }
    }

    int ans = solve();

    if(ans == -1) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";

    return 0;
}