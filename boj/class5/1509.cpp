#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 2500;
const int INF   = 1e8+1;

bool is_palindrome[MAX_N][MAX_N];
int dp[MAX_N+1];

int solve(int idx) {
    if(idx < 0) return 0;

    if(dp[idx] != INF) return dp[idx];

    for (int i = 0; i <= idx; i++)
    {
        if(is_palindrome[i][idx]) {
            dp[idx] = min(dp[idx], 1 + solve(i-1));
        }
    }

    return dp[idx];
}

int main() {
    // freopen("input.txt", "r", stdin);
    string str;
    int len;

    cin >> str;
    len = (int)str.size();

    for (int i = 0; i < len; i++)
    {
        is_palindrome[i][i] = true;
        dp[i] = INF;

        if(i+1 < len && str[i] == str[i+1]) is_palindrome[i][i+1] = true;
    }
    
    for (int k = 2; k < len; k++)
    {
        for (int i = 0; i < len-k; i++)
        {
            int j = i+k;
            if(str[i] == str[j] && is_palindrome[i+1][j-1]) is_palindrome[i][j] = true;
        }
    }
    
    int ans = solve(len-1);
    cout << ans << '\n';

    return 0;
}