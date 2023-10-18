#include <iostream>
#include <algorithm>

#define MAX_N 2000

using namespace std;

int n;
long long arr[2000];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = n-1;
        while (l < r)
        {
            if(l == i) {
                l++;
                continue;
            }
            
            if(r == i) {
                r--;
                continue;
            }

            if(arr[i] == arr[r] + arr[l]){
                ans++;
                break;
            }else if(arr[i] > arr[r] + arr[l]) l++;
            else r--;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}