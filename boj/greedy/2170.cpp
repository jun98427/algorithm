#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_N 1000000

using namespace std;

pair<int, int> arr[MAX_N];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr, arr+n);

    int l = arr[0].first, r = arr[0].second;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        if(arr[i].first <= r) {
            r = max(arr[i].second, r);
        }else {
            ans += r - l;
            l = arr[i].first;
            r = arr[i].second;
        }
    }

    ans += r - l;

    cout << ans << endl;
    
    return 0;
}