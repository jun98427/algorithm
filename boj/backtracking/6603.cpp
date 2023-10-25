#include <iostream>

#define M 6

using namespace std;

int ans[6];
int arr[13];
int k;

void dfs(int d, int idx) {
    // cout << "d : " << d << " idx : " << idx << "\n";
    if(d == M) {
        for (int i = 0; i < M; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    if(idx == k) return;

    for (int i = idx; i < k; i++)
    {
        ans[d] = arr[i];
        dfs(d+1, i+1);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    while (true)
    {
        cin >> k;
        if(k == 0) break;

        for (int i = 0; i < k; i++)
        {
            cin >> arr[i];
        }

        dfs(0, 0);    
        cout << "\n";
    }
    

    return 0;
}