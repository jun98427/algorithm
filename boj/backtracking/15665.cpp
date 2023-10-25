#include <iostream>
#include <algorithm>

#define MAX_N 8

using namespace std;

int arr[MAX_N];
int ans[MAX_N];
int n, m;

void dfs(int d) {
    if(d == m) {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return ;
    }

    int tmp = 0;

    for (int i = 0; i < n; i++)
    {
        if(tmp != arr[i]) {
            ans[d] = arr[i];
            tmp = arr[i];
            dfs(d+1);
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
    dfs(0);

    return 0;
}