#include <iostream>
#include <algorithm>

#define MAX_N 7

using namespace std;

int m, n;
int arr[MAX_N];
int ans[MAX_N];

void dfs(int d) {
    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return ;
    }

    for (int i = 0; i < n; i++)
    {
        ans[d] = arr[i];
        dfs(d+1);
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    dfs(0);

    return 0;
}