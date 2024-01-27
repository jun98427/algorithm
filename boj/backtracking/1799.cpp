#include <iostream>
#include <tuple>
#include <cstdio>

using namespace std;

const int MAX_N = 10;
int ans, n;

int map[MAX_N][MAX_N];
bool left_way[21], right_way[21];

void solve(int idx, int cnt) {
    if(idx >= 2*n-1) {
        ans = max(cnt, ans);
        return ;
    }

    bool flag = false;

    for (int i = 0; i < n-abs(idx - n + 1); i++)
    {
        int y = (n - 1 <= idx) ? n -1 - i : idx - i;
        int x = (n - 1 <= idx) ? idx - n + 1 + i : i; 

        if(map[y][x] == 1 && !right_way[idx] && !left_way[n - 1 + x - y]) {
            flag = true;

            right_way[idx] = true;
            left_way[n - 1 + x - y] = true;

            solve(idx+1, cnt+1);

            right_way[idx] = false;
            left_way[n - 1 + x - y] = false;
        }
    }
    
    if(!flag) solve(idx+1, cnt);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    solve(0, 0);

    cout << ans << endl;

    return 0;
}