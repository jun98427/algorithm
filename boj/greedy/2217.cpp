#include <iostream>
#include <algorithm>
#include <functional>

#define MAX_N 100000

using namespace std;

int arr[MAX_N+1];
int n;

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    sort(arr+1, arr+n+1, greater<int>());

    int ans = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    

    for (int i = 1; i <= n; i++)
    {
        int weight = i * arr[i];
        ans = max(ans, weight);
    }
    
    cout << ans << endl;

    return 0;
}