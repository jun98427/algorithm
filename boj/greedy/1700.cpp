#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>

#define MAX_K   100
#define INF     1e8

using namespace std;

int arr[MAX_K+1];
int next_k[MAX_K+1];
int is_using[MAX_K+1];
int n, k;

int main() {
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> arr[i];
    }

    memset(is_using, -1, (k+1) * sizeof(int));

    for (int i = k; i > 0; i--)
    {
        int t = arr[i];
        next_k[i] = is_using[t];
        if(next_k[i] == -1) next_k[i] = INF;
        is_using[t] = i;
    } 

    memset(is_using, 0, (k+1)*sizeof(int));

    int cur_cnt = 0;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        // for (int j = 1; j <= k; j++)
        // {
        //     cout << (is_using[j]== INF? -1 : is_using[j]) << " ";
        // }
        // cout << endl;
        

        int cur = arr[i];
        if(cur_cnt >= n && is_using[cur] == 0){
            int out, e = 0;
            for (int j = 1; j <= k; j++)
            {
                if(is_using[j] > e){
                    e = is_using[j];
                    out = j;
                }
            }
            is_using[out] = 0;        
            ans++;
        }else if(is_using[cur] == 0) cur_cnt++;

        is_using[cur] = next_k[i];
    }

    cout << ans << endl;

    return 0;
}