#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

#define MAX_HW  1000
#define DIR     4

using namespace std;

int h, w;
char board[MAX_HW][MAX_HW];
int isv[MAX_HW][MAX_HW];

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

vector<pair<int, int> > fires;
pair<int, int> loc;

bool isIn(int r, int c) {
    return r >= 0 && r < h && c >= 0 && c < w;
}

int BFS() {
    int r, c;
    
    queue<pair<int, int > > que;
    for(pair<int, int> f : fires) {
        tie(r, c) = f;
        isv[r][c] = -1;
        que.push(f);
    }

    tie(r, c) = loc;
    que.push(loc);
    isv[r][c] = 1;

    while (!que.empty())
    {
        tie(r, c) = que.front();
        que.pop();

        int v = isv[r][c];

        if(r == 0 || r == h-1 || c == 0 || c == w-1) {
            if(v > 0) return v;
        }

        int nv = (v > 0 ? v+1 : v-1);

        for(int i=0; i<DIR; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc) || 
                isv[nr][nc] != 0 || board[nr][nc] == '#') continue;
            
            isv[nr][nc] = nv;
            que.push({nr, nc});
        }
    }
    
    return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> w >> h;
        fires.clear();
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> board[i][j];
                isv[i][j] = 0;
                if(board[i][j] == '*') fires.push_back({i, j});
                else if(board[i][j] == '@') loc = {i, j};
            }
        }

        int ret = BFS();

        if(ret == -1) cout << "IMPOSSIBLE\n";
        else cout << ret << "\n"; 
    }
    

    return 0;
}