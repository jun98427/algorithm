#include <iostream>
#include <algorithm>

#define MAX_N 8

using namespace std;

int m, n;
int arr[MAX_N];
int ans[MAX_N];

void dfs(int idx, int d) {
    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return ;
    }

    if(idx == n) return ;

    for (int i = idx; i < n; i++)
    {
        ans[d] = arr[i];
        dfs(i+1, d+1);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    dfs(0, 0);

    return 0;
}