#include <iostream>
#include <queue>
#include <tuple>

#define MAX_NM  1000
#define DIR     4
#define MAX_P   9

using namespace std;

int board[MAX_NM][MAX_NM];
int moves[MAX_P+1];
queue<pair<int, int> >locs[MAX_P+1];
int areas[MAX_P+1];
int n, m, p;

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m && board[r][c] != '#'; 
}

bool isInt(char c) {
    return c >= '1' && c <= '9';
}

void Conquer(int cur) {
    queue<tuple<int, int, int> > que;
    
    int limit = moves[cur], r, c, d;
    while (!locs[cur].empty())
    {   
        tie(r, c) = locs[cur].front();
        que.push({r, c, 0});
        locs[cur].pop();
    }
    
    while (!que.empty())
    {
        tie(r, c, d) = que.front();
        que.pop();

        if(d == limit) {
            locs[cur].push({r, c});
            continue;
        }

        for(int i=0; i<DIR; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc) || board[nr][nc] != 0) {
                continue;
            }

            board[nr][nc] = cur;
            areas[cur]++;
            que.push({nr, nc, d+1});
        }
    }
}

bool Simulate() {
    int ret = false;
    for(int i=1; i<=p; i++) {
        if(!locs[i].empty()) {
            ret = true;
            Conquer(i);
        }
    }
    return ret;
}

void PrintBoard() {
    cout << "------\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) cout << board[i][j] << ' ';
        cout << "\n";
    }
    cout << "------\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("in.txt", "r", stdin);
    cin >> n >> m >> p;
    for(int i=1; i<=p; i++) cin >> moves[i];

    char c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> c;
            if(isInt(c)) {
                int cur_p = c - '0';
                board[i][j] = cur_p;
                locs[cur_p].push({i, j});
                areas[cur_p]++;
            }else if(c == '#') {
                board[i][j] = -1;
            }
        }
    }

    while (Simulate()){
        // PrintBoard();
    }

    for(int i=1; i<=p; i++) cout << areas[i] << " ";
    cout << "\n";

    return 0;
}