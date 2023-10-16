#include <iostream>

#define DIR_NUM 3

using namespace std;

int map[17][17];
int n;

int dx[3] = {1, 1, 0};
int dy[3] = {0, 1, 1};

int ans;

bool is_valid(int y, int x) {
    return y >= 1 && y <= n && x >= 1 && x <= n && map[y][x] == 0;
}

void DFS(int y, int x, int dir) 
{
    // cout << "y : " << y << " x : " << x << " dir : " << dir << endl;
    if(y==n && x==n) 
    {
        ans++;
        return;
    }

    for (int i = 0; i < DIR_NUM; i++)
    {
        if(dir != 1 && dir+i == 2) continue;

        int ny = y + dy[i];
        int nx = x + dx[i];

        if(!is_valid(ny, nx)) continue;
        
        if(i == 1 && (map[y+1][x] == 1 || map[y][x+1] == 1)) continue;
        
        DFS(ny, nx, i);
    }
    
}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    
    DFS(1, 2, 0);

    cout << ans << endl;
    return 0;
}