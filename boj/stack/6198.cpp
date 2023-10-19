#include <iostream>
#include <stack>
#include <tuple>

#define MAX_N 80000

using namespace std;

int arr[MAX_N];
long long dp[MAX_N];
int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    stack<pair<int, int> > s;
    long long ans = 0;

    for (int i = n-1; i >= 0; i--)
    {
        while (!s.empty())
        {
            if(s.top().first >= arr[i]) break;
            dp[i] += dp[s.top().second] + 1;
            s.pop();
        }

        s.push(make_pair(arr[i], i));
        ans += dp[i];
    }

    cout << ans << endl;

    return 0;
}