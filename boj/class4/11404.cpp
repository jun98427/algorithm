#include <iostream>

#define MAX_N   100
#define INF     100000007

using namespace std;

int dist[MAX_N+1][MAX_N+1];
int n, m;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == j) dist[i][i] = 0;
            else dist[i][j] = INF;
        }
    }

    int to, from, val;
    
    while (m--)
    {
        cin >> to >> from >> val;
        dist[to][from] = min(dist[to][from], val);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (dist[i][j] != INF ? dist[i][j] : 0) << " ";
        }
        cout << "\n";
    }

    return 0;
}

