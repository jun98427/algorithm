#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_MV = 10;
const int DIR    = 4;
const int INF    = 1e8+1;

int n, m;
char board[MAX_MV+1][MAX_MV][MAX_MV];
pair<int, int> at[MAX_MV+1][2];

vector<pair<int, int> > Move(int idx, int dir) {
    
}

int solve(int idx) {
    int ret = MAX_MV + 1;

    int br, bc, rr, rc;

    tie(rr, rc) = at[idx][0];
    tie(br, bc) = at[idx][1];

    for (int i = 0; i < DIR; i++)
    {
    }
    
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    
    cin >> n >> m;
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ch;
            board[0][i][j] = ch;

            if(ch == 'R') at[0][0] = {i, j};
            else if(ch == 'B') at[0][1] = {i, j};
        }
    }
    


    return 0;
}