#include <iostream>
#include <string>
#include <map>

#define DIR_NUM 8

using namespace std;

int dr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int n, m, k;
char arr[10][10];
map<string, int> mapper;

void DFS(int r, int c, string cur)
{
    mapper[cur]++;

    if(cur.size() == 5) return;

    int nr, nc;
    for (int i = 0; i < DIR_NUM; i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];

        if(nr == -1) nr = n-1;
        else if(nr == n) nr = 0;

        if(nc == -1) nc = m-1;
        else if(nc == m) nc = 0;

        DFS(nr, nc, cur + arr[nr][nc]);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << arr[i][j] << " ";
            string tmp = "";
            DFS(i, j, tmp + arr[i][j]);
        }
        // cout << "\n";
    }

    string str;
    while (k--)
    {
        cin >> str;
        cout << mapper[str] << "\n";
    }
    
    return 0;
}