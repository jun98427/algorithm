#include <iostream>
#include <algorithm>

#define MAX_N 8

using namespace std;

int arr[MAX_N];
int ans[MAX_N];
int n, m;
bool used[MAX_N];

void dfs(int d, int idx) {
    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return ;
    }

    if(idx == n) return ;

    int tmp = 0;

    for (int i = idx; i < n; i++)
    {
        if(!used[i] && tmp != arr[i]) {
            used[i] = true;
            ans[d] = arr[i];
            tmp = arr[i];
            dfs(d+1, i+1);
            used[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n); 
    dfs(0, 0);

    return 0;
}