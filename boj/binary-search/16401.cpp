#include <iostream>
#include <algorithm>

#define MAX_N 1000000

using namespace std;

int n, base;

int arr[1000000];

bool is_possible(int mid){
    int cnt = 0;
    for(int i=n-1; i>=0; i--) 
    {   
        if(arr[i] < mid) break;
        cnt += arr[i] / mid;

        if(cnt >= base) return true;
    }

    return false;
}

int main() {
    cin >> base >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int s = 1, e = 1000000000, mid;
    int ans = 0;

    while (s <= e)
    {
        mid = (s + e) / 2;

        if(is_possible(mid)) 
        {
            s = mid+1;
            ans = max(ans, mid);
        }else {
            e = mid-1;
        }
    }
    
    cout << ans << endl;

    return 0;
}