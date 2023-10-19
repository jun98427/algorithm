#include <iostream>

#define MAX_N 10000

using namespace std;

int n, m;
int arr[MAX_N];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int r=-1, sum=0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (r+1 < n && sum + arr[r+1] <= m)
        {
            r++;
            sum += arr[r];   
        }
        
        if(sum == m) ans++;

        sum -= arr[i];
    }
    
    cout << ans << endl;

    return 0;
}