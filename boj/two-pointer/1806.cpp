#include <iostream>

#define INF     100001
#define MAX_N   100000

using namespace std;

int n, s;
int arr[MAX_N];

int main() {
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int j = 0;
    int sum = 0;
    int ans = INF;

    for (int i = 0; i < n; i++)
    {
        while (j < n)
        {
            if(sum >= s) break;
            
            sum += arr[j];
            j++;
        }

        // cout << "i : " << i << " j : " << j << endl;
        if(sum >= s) {
            ans = min(ans, j - i);
        }

        sum -= arr[i];
    }
    
    cout << (ans == INF? 0 : ans) << endl;

    return 0;
}