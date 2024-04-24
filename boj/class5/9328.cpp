#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

const int MAX_HW = 100;
const int CHAR_N = 26;
const int DIR    = 4;

char map[MAX_HW+2][MAX_HW+2];
bool visited[MAX_HW+2][MAX_HW+2];
queue<pair<int, int> > loc[CHAR_N];

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

bool keys[CHAR_N];
int h, w, ans;

bool isIn(int r, int c) {
    return r >= 0 && r < h+2 && c >= 0 && c < w+2;
}

bool isKey(char c) {
    return c >= 'a' && c <= 'z';
}

bool isDoor(char c) {
    return c >= 'A' && c <= 'Z';
}

void Input(){
    cin >> h >> w;
    for(int i=0; i< h+2; i++) {
        for(int j=0; j<w+2; j++) {
            if(i == 0 || i == h+1) map[i][j] = '.';
            else if(j==0 || j==w+1) map[i][j] = '.';
            else cin >> map[i][j];
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < CHAR_N; i++)
    {
        keys[i] = false;
        loc[i] = queue<pair<int, int> > ();
    }

    string k;
    cin >> k;

    for(int i=0; i<k.size(); i++) {
        if(isKey(k[i])) keys[k[i] - 'a'] = true;
    }
}

void Solve() {
    queue<pair<int, int> > que;
    que.push({0, 0});
    visited[0][0] = true;

    int cr, cc;
    while (!que.empty())
    {
        tie(cr, cc) = que.front();
        que.pop();

        int nr, nc;
        for (int i = 0; i < DIR; i++)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];

            if(!isIn(nr, nc) || visited[nr][nc] || 
                map[nr][nc] == '*') continue;

            if(map[nr][nc] == '.') {
                visited[nr][nc] = true;
                que.push({nr, nc});
            }else if(map[nr][nc] == '$'){
                visited[nr][nc] = true;
                ans++;
                que.push({nr, nc});
            }else if(isKey(map[nr][nc])) {
                visited[nr][nc] = true;
                que.push({nr, nc});
                int idx = map[nr][nc] - 'a';

                if(!keys[idx]) {
                    keys[idx] = true;

                    while (!loc[idx].empty())
                    {
                        int lr, lc;
                        tie(lr, lc) = loc[idx].front();
                        loc[idx].pop();

                        visited[lr][lc] = true;
                        que.push({lr,lc});
                    }   
                }
            }else if(isDoor(map[nr][nc])) {
                int idx = map[nr][nc] - 'A';
                if(keys[idx]) {
                    visited[nr][nc] = true;
                    que.push({nr, nc});
                }else {
                    loc[idx].push({nr, nc});
                }
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;
    while (tc--)
    {
        Input();
        
        ans = 0;

        Solve();

        cout << ans << "\n";
    }
    
    return 0;
}