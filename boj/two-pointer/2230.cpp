#include <iostream>
#include <algorithm>

#define MAX_N   100000

using namespace std;

int n, m;
int arr[MAX_N+1];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int j=0;
    int ans = arr[n-1] - arr[0];

    for (int i = 0; i < n-1; i++)
    {
        while (j < n && arr[j] - arr[i] < m)
        {
            j++;
        }

        // cout << "i : " << i << " j : " << j << endl;
        int gap = arr[j] - arr[i];
        if(gap < m) break;
        
        ans = min(ans, arr[j] - arr[i]);
    }
    
    cout << ans << endl;

    return 0;
}