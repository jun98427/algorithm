#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 100'000;
const int INF = 1e8+7;
const int CASE = 5;

int cmds[MAX_N+1];
int dp[MAX_N+1][5][5];
int cnt;

// 중앙 1 위 2 오른쪽 3 아래 4 왼쪽 

int calc(int t, int move) {
    if(t == move) return 1;
    else if(move == 0) return 2;
    else if(abs(t - move) == 2) return 4;
    return 3;
}

void solve(int d) {
    if(d > cnt) {
        return ;
    }

    int t = cmds[d];

    for (int r = 0; r < CASE; r++)
    {
        for (int l = 0; l < CASE; l++)
        {
            int cur = dp[d-1][r][l];

            if(cur == -1 || cur == INF) continue;

            int r_mov = calc(t, r);
            int l_mov = calc(t, l);

            if(dp[d][t][l] == -1 || dp[d][t][l] > cur + r_mov) dp[d][t][l] = cur+r_mov;
            if(dp[d][r][t] == -1 || dp[d][r][t] > cur + l_mov) dp[d][r][t] = cur+l_mov;
        }
    }
    
    solve(d+1);
}

int main() {
    // freopen("input.txt", "r", stdin);
    int val;

    while(true)
    {
        cin >> val;
        if(val == 0) break;

        cmds[++cnt] = val;
    }

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            dp[0][i][j] = INF;
        }
    }
    
    dp[0][0][0] = 0;
    
    solve(1);

    // for (int i = 0; i <= cnt; i++)
    // {
    //     for (int r = 0; r < CASE; r++)
    //     {
    //         for (int l = 0; l < CASE; l++)
    //         {
    //             cout << (dp[i][r][l] >= INF ? -1 : dp[i][r][l]) << " ";
    //         }
    //     }
    //     cout << "\n";
    // }
    

    int ans = INF;
    for (int i = 0; i < CASE; i++)
    {
        for (int j = 0; j < CASE; j++)
        {
            if(dp[cnt][i][j] != -1 && ans > dp[cnt][i][j]) ans = dp[cnt][i][j];
        }
    }
    
    cout << ans << "\n";

    return 0;
}