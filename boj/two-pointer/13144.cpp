#include <iostream>

#define MAX_N   100000
#define MAX_VAL 100000

using namespace std;

int n;
int arr[MAX_N];
bool isin[MAX_CNT+1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int j = -1;

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (j+1 < n && !isin[arr[j+1]])
        {
            j++;
            isin[arr[j]] = true;
        }

        // cout << " i : " << i << " j : " << j << endl;

        ans += (j - i + 1);
        isin[arr[i]] = false;    
    }
    
    cout << ans << endl;

    return 0;
}