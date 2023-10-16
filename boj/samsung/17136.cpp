#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>

#define MAP_SIZE        10
#define PAPER_COUNT     5
#define INF             100000

using namespace std;

int map[MAP_SIZE][MAP_SIZE];
bool is_covered[MAP_SIZE][MAP_SIZE];
int remain[PAPER_COUNT+1] = {0, 5, 5, 5, 5, 5};
vector<pair<int, int> > required;

int ans = INF;

// 일단은 완탐으로 ㄱㄱ

bool is_possible(int y, int x, int len) {
    if(y+len > 10 || x+len > 10) return false;

    for (int i = y; i < y+len; i++)
    {
        for (int j = x; j < x + len; j++)
        {
            if(map[i][j] == 0 || is_covered[i][j]) return false;
        }
    }

    return true;
}

void reverse(int y, int x, int len) 
{
    for (int i = y; i < y+len; i++)
    {
        for (int j = x; j < x + len; j++)
        {
            is_covered[i][j] = !is_covered[i][j];
        }
    }
}

void DFS(int idx, int cnt) 
{
    if(idx == required.size()) {
        ans = min(ans, cnt);
        return ;
    }

    if(is_covered[required[idx].first][required[idx].second]) {
        DFS(idx+1, cnt);
    }

    for (int i = 1; i <= PAPER_COUNT; i++)
    {
        if(remain[i] <= 0) continue;

        if(!is_possible(required[idx].first, required[idx].second, i)) break;

        reverse(required[idx].first, required[idx].second, i);
        remain[i]--;
        DFS(idx+1, cnt+1);
        reverse(required[idx].first, required[idx].second, i);
        remain[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            cin >> map[i][j];
            if(map[i][j]) required.push_back(make_pair(i, j));
        }
    }

    DFS(0, 0);

    cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}