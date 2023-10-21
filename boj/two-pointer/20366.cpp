#include <iostream>
#include <algorithm>
#include <cstdio>

#define MAX_N   600

using namespace std;

int arr[MAX_N];
int n;

int get_temp(int l, int r, int t) {
    int ret = t;

    int s = l+1;
    int e = r-1;

    while (s < e)
    {
        int val = arr[s] + arr[e];

        ret = min(ret, abs(t - val));
        if(ret == 0) break;

        if(val > t) {
            e--;
        }else {
            s++;
        }
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int ans = abs(arr[0] + arr[n-1] - arr[1] - arr[n-2]);

    for (int i = 0; i < n-3; i++)
    {
        for (int j = i+3; j < n; j++)
        {
            int t = get_temp(i, j, arr[i] + arr[j]);
            ans = min(ans, t);
        }
    }
    
    cout << ans << endl;

    return 0;
}