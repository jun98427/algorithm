#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAP_SIZE = 9;

int map[MAP_SIZE][MAP_SIZE];
vector<pair<int, int> > targets;

bool DFS(int idx) 
{
    if(idx == targets.size()) return true;
    
    int already[MAP_SIZE+1] = {0, };
    int row, col;
    tie(row, col) = targets[idx];

    for (int i = 0; i < MAP_SIZE; i++)
    {
        already[map[row][i]] = 1;
        already[map[i][col]] = 1;
    }

    int t_row = row - row % 3;
    int t_col = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            already[map[t_row+i][t_col+j]] = 1;
        }
    }

    for (int i = 1; i <= MAP_SIZE; i++)
    {
        if(already[i] == 0) {
            map[row][col] = i;
            if(DFS(idx+1)) return true;
            map[row][col] = 0;
        }
    }
    
    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);
    char c;
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            cin >> c;
            map[i][j] = c - '0';

            if(map[i][j] == 0) targets.push_back({i, j});
        }
    }
    
    DFS(0);

    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}