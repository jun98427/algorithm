#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

#define MAX_N   100
#define DIR     4

using namespace std;

enum STATE{
    STATE_OFF,
    STATE_ON,
    STATE_V,
};

STATE board[MAX_N+1][MAX_N+1];
vector<pair<int, int> > switches[MAX_N+1][MAX_N+1];
int n, m;
int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return r>0 && r<=n && c>0 && c<=n;
}

bool isCon(int r, int c) {
    for(int i=0; i<DIR; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(!isIn(nr, nc)) continue;

        if(board[nr][nc] == STATE_V) return true;
    }
    return false;
} 

int Solve() {
    int ret = 1;
    queue<pair<int, int> > que;
    que.push({1, 1});
    board[1][1] = STATE_ON;

    // switch 를 켠 방이 방문한 곳과 붙어있는 지 확인 필요
    // 현재 방에서 나아갈 수 있는 지 확인 필요
    int r, c;
    while(!que.empty()) {
        tie(r, c) = que.front();
        que.pop();
        
        if(board[r][c] != STATE_ON) continue;
        board[r][c] = STATE_V;

        for(pair<int, int> sw : switches[r][c]) {
            int sr, sc;
            tie(sr, sc) = sw;

            if(board[sr][sc] == STATE_OFF) {
                ret++;
                board[sr][sc] = STATE_ON;
            }

            if(board[sr][sc] == STATE_ON) {
                bool ch = isCon(sr, sc);

                if(ch) que.push({sr, sc});
            }
        }

        for(int i=0; i<DIR; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc) || board[nr][nc] != STATE_ON) continue;

            que.push({nr, nc});
        }
    }

    return ret;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> m;

    while (m--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        switches[r1][c1].push_back({r2, c2}); 
    }
    
    int ans = Solve();

    cout << ans << "\n";

    return 0;
}