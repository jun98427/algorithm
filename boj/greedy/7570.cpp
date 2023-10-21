#include <iostream>

#define MAX_N 1000000

using namespace std;

int n;
int dp[MAX_N+1];

int main() {
    cin >> n;

    int val, max_val = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> val;

        dp[val] = dp[val-1] + 1;
        max_val = max(max_val, dp[val]);
    }

    cout << n - max_val << endl;

    return 0;
}