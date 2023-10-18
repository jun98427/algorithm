#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 4000

using namespace std;

int arr[MAX_N][4];
int n;

vector<int> vec[2];

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = arr[i][0] + arr[j][1];
            vec[0].push_back(sum);
            sum = arr[i][2] + arr[j][3];
            vec[1].push_back(sum);
        }
    }

    long long ans = 0;

    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end());
    
    int i = 0;
    while (i < vec[0].size())
    {
        int next_i = upper_bound(vec[0].begin(), vec[0].end(), vec[0][i]) - vec[0].begin();

        int cnt = upper_bound(vec[1].begin(), vec[1].end(), -vec[0][i]) - lower_bound(vec[1].begin(), vec[1].end(), -vec[0][i]);

        ans += (long long)cnt * (next_i - i);
        i = next_i;
    }
    
    cout << ans << endl;

    return 0;
}