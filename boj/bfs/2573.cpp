#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>

#define DIR     4
#define MAX_NM  300

using namespace std;

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};
int board[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];
vector<pair<int, int> > loc;


int n, m;

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void BFS(int sr, int sc) {
    queue<pair<int, int> > q;
    q.push({sr, sc});

    visited[sr][sc] = true;

    int r, c;
    while (!q.empty())
    {
        tie(r, c) = q.front();
        q.pop();

        int dec = 0;
        for(int i=0; i<DIR; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc) || visited[nr][nc]) continue;

            if(board[nr][nc] <= 0) dec++;
            else {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }

        board[r][c] -= dec;
    }
}

int Solve() {
    memset(visited, false, sizeof(visited));
    
    int sr, sc, ret = 0;
    for(auto it : loc) {
        tie(sr, sc) = it;
        if(board[sr][sc] <= 0) continue;

        if(!visited[sr][sc]) {
            if(ret != 0) return 2;

            ret++;
            BFS(sr, sc);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if(board[i][j] > 0) loc.push_back({i, j});
        }
    }

    int ans = 0;
    while (true)
    {
        int ret = Solve();
        if(ret != 1) {
            if(ret == 0) ans = 0;
            break;
        }

        ans++;
    }
    
    cout << ans << "\n";
    
    return 0;
}