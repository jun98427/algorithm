#include <iostream>

#define MAX_N 10000

using namespace std;

int n, total;
int arr[MAX_N];

bool is_possible(int mid) 
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(mid, arr[i]);

        if(sum > total) return false;
    }
    
    return true;
}

int main() {
    cin >> n;

    int s = 1, e = -1, mid;

    for(int i=0; i<n; i++) { 
        cin >> arr[i];
        e = max(e, arr[i]);
    }
    
    cin >> total;

    int ans = 0;

    while (s <= e)
    {
        mid = (s + e) / 2;

        if(is_possible(mid)) {
            ans = max(ans, mid);
            s = mid+1;
        }else{
            e = mid-1;
        }
    }   
    
    cout << ans << endl;
    
    return 0;
}