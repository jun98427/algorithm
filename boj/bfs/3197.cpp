#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_RC  1500
#define DIR     4

using namespace std;

int board[MAX_RC][MAX_RC];
int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};
vector<pair<int, int> > loc;

int n, m, max_val;
int parent[MAX_RC];
queue<pair<int, int> >que;

bool isIn(int r, int c) {
    return r>=0 && r<n && c>=0 && c<m;
}

void fillBoard() {
    int r, c;
    while (!que.empty())
    {
        tie(r, c) = que.front();
        que.pop();

        int v = board[r][c];
        max_val = max(max_val, v);

        for(int i=0; i<DIR; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc) || board[nr][nc]!=-1) continue;

            board[nr][nc] = v+1;
            que.push({nr, nc});
        }
    }
}

bool CanReach(int l) {
    bool isv[MAX_RC][MAX_RC] = {false, };
    int sr, sc, er, ec;
    tie(sr, sc) = loc[0];
    tie(er, ec) = loc[1];

    isv[sr][sc] = true;

    queue<pair<int, int> > que;
    que.push({sr, sc});

    int r, c;
    while (!que.empty())
    {
        tie(r, c) = que.front();
        que.pop();

        if(r == er && c == ec) return true;

        for(int i=0; i<DIR; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc) || isv[nr][nc]) continue;

            if(board[nr][nc] <= l) {
                que.push({nr, nc});
                isv[nr][nc] = true;
            }
        }
    }
    
    return false;
}

int Solve() {
    int s = 0, e = max_val, mid, ret;

    while (s <= e)
    {
        int mid = (s+e) / 2;
        
        if(CanReach(mid)) {
            ret = mid;
            e = mid-1;
        }else {
            s = mid+1;
        }
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;

    char c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> c;
            if(c == 'X') board[i][j] = -1;
            else if(c == 'L') {
                board[i][j] = 0;
                loc.push_back({i, j});
                que.push({i, j});
            }else {
                board[i][j] = 0;
                que.push({i, j});
            }
        }
    }

    fillBoard();

    int ans = Solve();

    cout << ans << "\n";

    return 0;
}