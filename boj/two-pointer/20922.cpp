#include <iostream>

#define MAX_N   200000
#define MAX_V   100000

using namespace std;

int n, k;
int arr[MAX_N+1];
int mapper[MAX_V+1];

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int j = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (j+1 <= n && mapper[arr[j+1]] < k)
        {
            j++;
            mapper[arr[j]]++;
        }

        ans = max(ans, j-i+1);

        mapper[arr[i]]--;
    }
    
    cout << ans << endl;
    
    return 0;
}