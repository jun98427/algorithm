#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int ans[8];
bool used[8];

void dfs(int d){
    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] <<" ";
        }
        cout << "\n";
        return ;
    }

    for (int i = 0; i < n; i++)
    {
        if(!used[i]) {
            ans[d] = arr[i];
            used[i] = true;
            dfs(d+1);
            used[i] = false;
        }
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