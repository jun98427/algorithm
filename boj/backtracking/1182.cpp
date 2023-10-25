#include <iostream>

using namespace std;

int arr[20];
int ans;
int n, s;

void dfs(int d, int val, int cnt) {
    if(d == n) {
        if(val == s && cnt != 0) ans++;

        return ;
    }

    dfs(d+1, val+arr[d], cnt+1);

    dfs(d+1, val, cnt);
}

int main() {
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    dfs(0, 0, 0);

    cout << ans << "\n";

    return 0;
}