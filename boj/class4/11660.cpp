#include <iostream>

#define MAX_N 1024

using namespace std;

using ll = long long;

ll board[MAX_N+1][MAX_N+1];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;


    for (int i = 1; i <= n; i++)
    {   
        ll sum = 0;
        int val;

        for (int j = 1; j <= n; j++)
        {
            cin >> val;

            sum += val;
            board[i][j] = sum;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            board[i][j] += board[i-1][j];
        }
    }

    while (m--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // cout << board[r2][c2] << " " << board[r2][c1-1] << " " << board[r1-1][c2] << " " << board[r1-1][c2-1] << "\n";
        ll ans = board[r2][c2] - board[r2][c1-1] - board[r1-1][c2] + board[r1-1][c1-1];
        cout << ans << "\n";
    }

    return 0;
}