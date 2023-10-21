#include <iostream>

#define MAX_N 1000000
#define MAX_K 100000

using namespace std;

int n, k;
int arr[MAX_N];

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int j = -1;
    int ans = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        while (j+1 < n && (arr[j+1]%2 == 0) || (arr[j+1]%2 == 1 && cnt < k))
        {
            j++;
            if(arr[j] % 2 == 1) cnt++;
        }

        ans = max(ans, j-i-cnt+1);

        if(arr[i] % 2 == 1) cnt--;
    }

    cout << ans << endl;
    
    return 0;
}