#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_M   100

using namespace std;

int n, m, l;
int arr[MAX_M];
vector<int> vec;

bool is_possible(int mid) 
{
    int cnt = 0;

    for(int val : vec) 
    {
        if(val <= mid) continue;

        cnt += val / mid;
        if(val % mid == 0) cnt--;
    }
    
    return cnt <= m;
}

int main() {
    cin >> n >> m >> l;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(arr[i] - prev);
        prev = arr[i];
    }
    vec.push_back(l - prev); 
    
    int s = 1, e = l, mid;
    int ans = l;

    while (s <= e)
    {
        mid = (s + e) / 2;

        if(is_possible(mid)) {
            ans = min(ans, mid);
            e = mid - 1;
        }else {
            s = mid+1;
        }
    }
    
    cout << ans << endl;

    return 0;
}