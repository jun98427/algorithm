#include <iostream>
#include <tuple>
// #include <cstdio>

#define MAX_NUM     50
#define INF         1e9

using namespace std;

int n, m, k;
int ans = INF;
int map[MAX_NUM+1][MAX_NUM+1];
int tmp[MAX_NUM+1][MAX_NUM+1];
tuple<int, int, int> command[6];
bool is_used[6];
int order[6];

void Rotate(int idx)
{
    int r, c, s;
    tie(r, c, s) = command[idx];
    
    int cr, cc;
    while (s)
    {
        cr = r-s;
        cc = c-s;
        int tmep = tmp[cr][cc];
        int len = 2 * s;
        s--;

        for (int i = 0; i < len; i++)
        {
            tmp[cr][cc] = tmp[cr+1][cc];
            cr++;
        }

        for (int i = 0; i < len; i++)
        {
            tmp[cr][cc] = tmp[cr][cc+1];
            cc++;
        }

        for (int i = 0; i < len; i++)
        {
            tmp[cr][cc] = tmp[cr-1][cc];
            cr--;
        }

        for (int i = 0; i < len-1; i++)
        {
            tmp[cr][cc] = tmp[cr][cc-1];
            cc--;
        }

        tmp[cr][cc] = tmep;
    }
}


void Solve(){
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            tmp[i][j] = map[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        Rotate(order[i]);
    }

    int sum;
    // cout << "-----\n";
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= m; j++)
        {
            sum += tmp[i][j];
            // cout << tmp[i][j] << " ";
        }

        ans = min(ans, sum);
        // cout << endl;
    }

    return ;
}


void Comb(int idx, int m[][MAX_NUM+1]) {
    if(idx == k)
    {
        Solve();
        return;
    }
    
    for (int i = 0; i < k; i++)
    {
        if(!is_used[i]) {
            is_used[i] = true;
            order[idx] = i;
            Comb(idx+1, tmp);
            is_used[i] = false;     
        }
    }
}


int main() {
    // freopen("17406.txt", "r", stdin);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }

    int r, c, s;
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c >> s;
        command[i] = make_tuple(r, c, s);
    }

    Comb(0, map);

    cout << ans << endl;  

    return 0;
}