#include <iostream>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;
const int DIR   = 4;

int board[MAX_N][MAX_M];
int boundary[MAX_N][MAX_M];
int n, m;

map<int, int> mapper;

int dr[DIR] = {1, 0, -1, 0};
int dc[DIR] = {0, 1, 0, -1};

bool isIn(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void BFS(int r, int c, int ch) {
    queue<pair<int, int> > que;
    que.push({r, c});

    boundary[r][c] = ch;
    int num = 1;

    int cr, cc;

    while (!que.empty())
    {
        tie(cr, cc) = que.front();
        que.pop();

        for (int i = 0; i < DIR; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(isIn(nr, nc) && board[nr][nc] == 0 && boundary[nr][nc] == 0) {
                boundary[nr][nc] = ch;
                num++;
                que.push({nr, nc});
            }
        }
    }

    mapper[ch] = num;
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    char c;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j] == 0 && boundary[i][j] == 0) BFS(i, j, ++cur);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(board[i][j] == 0) {
                cout << 0;
                continue;
            }

            int tmp = 1;
            set<int> already;

            for (int k = 0; k < DIR; k++)
            {
                int r = i + dr[k];
                int c = j + dc[k];

                if(isIn(r, c) && board[r][c] == 0) {
                    if(already.find(boundary[r][c]) == already.end()) {
                        tmp += mapper[boundary[r][c]];
                        already.insert(boundary[r][c]);
                    }
                }
            }

            cout << tmp % 10;
        }
        cout << "\n";
    }

    return 0;
}