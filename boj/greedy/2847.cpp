#include <iostream>

#define MAX_N 100

using namespace std;

int arr[MAX_N];
int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = 0;
    int prev = arr[n-1];

    for (int i = n-2; i >= 0; i--)
    {
        if(arr[i] < prev) {
            prev = arr[i];
        }else {
            ans += arr[i] - prev + 1;
            prev--; 
        }
    }

    cout << ans << endl;
    
    return 0;
}