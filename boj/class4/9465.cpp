#include <iostream>

#define MAX_N   100000

using namespace std;

int n;
int value[2][MAX_N];
int dp[MAX_N][2][2];    // 현재의 칸에서 선택할 지 말지
                        // 선택 시 위의 것 선택 or 아래 것 선택

int main() {
    // freopen("input.txt", "r", stdin);
    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> n;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> value[i][j];
            }
        }

        dp[0][1][0] = value[0][0];
        dp[0][1][1] = value[1][0]; 

        int val;
        for (int i = 1; i < n; i++)
        {
            //현재 idx 에서 선택 x
            dp[i][0][0] = max(dp[i-1][0][0], max(dp[i-1][1][0], dp[i-1][1][1]));

            // 위의 것을 선택
            val = value[0][i];
            dp[i][1][0] = max(dp[i-1][1][1], dp[i-1][0][0]) + val;

            // 아래 것을 선택
            val = value[1][i];
            dp[i][1][1] = max(dp[i-1][1][0], dp[i-1][0][0]) + val;
        }

        int ans = max(dp[n-1][0][0], max(dp[n-1][1][0], dp[n-1][1][1]));
        cout << ans << "\n";
    }
    

    return 0;
}