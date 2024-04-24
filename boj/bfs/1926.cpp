#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_NM = 500;
const int DIR    = 4;

int board[MAX_NM][MAX_NM];
bool visited[MAX_NM][MAX_NM];

int n, m;

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m; 
}

int bfs(int r, int c) {
    int ret = 0;
    
    queue<pair<int, int> > que;
    que.push({r, c});
    visited[r][c] = true;

    int cr, cc;
    while (!que.empty())
    {
        tie(cr, cc) = que.front();
        que.pop();

        ret++;

        for(int i=0; i<DIR; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(!isIn(nr, nc)) continue;

            if(board[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                que.push({nr, nc});
            }
        }
    }
    
    return ret;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cin >> board[i][j];
    }

    int nums = 0, area = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 1 && !visited[i][j]) {
                nums++;
                area = max(area, bfs(i, j));
            }
        }
    }

    cout << nums << "\n" << area << "\n";

    return 0;
}