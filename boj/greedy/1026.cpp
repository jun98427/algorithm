#include <iostream>
#include <algorithm>
#include <functional>

#define MAX_N 50

using namespace std;

int n;
int arr[2][50];

int main() {
    cin >> n;

    for(int i=0; i < n; i++) cin >> arr[0][i];
    for (int i = 0; i < n; i++) cin >> arr[1][i];

    sort(arr[0], arr[0]+n, less<int>());
    sort(arr[1], arr[1]+n, greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += arr[0][i] * arr[1][i];
    }
    
    cout << ans << endl;

    return 0;
}