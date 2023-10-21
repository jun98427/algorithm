#include <iostream>
#include <tuple>

#define MAX_VAL 1000000
#define MAX_N   1000

using namespace std;

int prefix[MAX_CNT+2];

int n, k;

int main(){
    cin >> n >> k;

    int s, e, r=-1;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        prefix[s] += 1;
        prefix[e] -= 1;
        r = max(r, e);
    }

    for (int i = 1; i <= r; i++)
    {
        prefix[i] += prefix[i-1];
    }

    // for (int i = 0; i <= r; i++)
    // {
    //     cout << prefix[i] << " ";
    // }
    // cout << endl;
    

    int x = 0, y = 0;

    int sum = 0;
    int j = 0;
    for (int i = 0; i < r; i++)
    {
        while (j <= r && sum < k)
        {
            sum += prefix[j];
            j++;
        }

        // cout << "i : " << i << " j : " << j << " sum : " << sum << endl;

        if(sum == k) {
            x = i;
            y = j;
            break;
        }

        sum -= prefix[i];
    }

    cout << x << " " << y << endl;
    
    return 0;
}
