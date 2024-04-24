#include <iostream>
#include <deque>

using namespace std;
using ll = long long;

const int MAX_N = 20;
const int MAX_M = 5;

int n;
ll ans;
ll board[MAX_M+1][MAX_N][MAX_N];

// board을 넘기고 거기서 하나씩 생성해서?
// 움직일 수 있는 것을 확인하는 것이 중요?
bool right(int idx) {
    // cout << "right\n";
    deque<ll> dq;
    bool is_mv = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[idx][i][j] == 0) continue;

            if(!dq.empty() && board[idx][i][j] == dq.back()) {
                dq.pop_back();
                dq.push_back((board[idx][i][j] << 1) + 1);
            }else {
                dq.push_back(board[idx][i][j]);
            }
        }

        for (int j = 0; j < n; j++)
        {
            if(!dq.empty()) {
                board[idx+1][i][j] = (dq.front() & (~(ll)0x1));
                dq.pop_front();
            }else {
                board[idx+1][i][j] = 0;
            }

            ans = max(ans, board[idx+1][i][j]);
            if(board[idx][i][j] != board[idx+1][i][j]) is_mv = true;
        }
    }

    return is_mv;
}

bool left(int idx) {
    // cout << "left\n";
    deque<ll> dq;
    bool is_mv = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if(board[idx][i][j] == 0) continue;

            if(!dq.empty() && board[idx][i][j] == dq.back()) {
                dq.pop_back();
                dq.push_back((board[idx][i][j] << 1) + 1);
            }else {
                dq.push_back(board[idx][i][j]);
            }
        }

        for (int j = n-1; j >= 0; j--)
        {
            if(!dq.empty()) {
                board[idx+1][i][j] = (dq.front() & (~(ll)0x1));
                dq.pop_front();
            }else {
                board[idx+1][i][j] = 0;
            }

            ans = max(ans, board[idx+1][i][j]);
            if(board[idx][i][j] != board[idx+1][i][j]) is_mv = true;
        }
    }
    
    return is_mv;
}

bool upward(int idx) {
    // cout << "upward\n";
    deque<ll> dq;
    bool is_mv = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[idx][j][i] == 0) continue;

            if(!dq.empty() && board[idx][j][i] == dq.back()) {
                dq.pop_back();
                dq.push_back((board[idx][j][i] << 1) + 1);
            }else {
                dq.push_back(board[idx][j][i]);
            }
        }

        for (int j = 0; j < n; j++)
        {
            if(!dq.empty()) {
                board[idx+1][j][i] = (dq.front() & (~(ll)0x1));
                dq.pop_front();
            }else {
                board[idx+1][j][i] = 0;
            }

            ans = max(ans, board[idx+1][j][i]);
            if(board[idx][j][i] != board[idx+1][j][i]) is_mv = true;
        }
    }

    return is_mv;
}

bool downward(int idx) {
    // cout << "down\n";
    deque<ll> dq;
    bool is_mv = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if(board[idx][j][i] == 0) continue;

            if(!dq.empty() && board[idx][j][i] == dq.back()) {
                dq.pop_back();
                dq.push_back((board[idx][j][i] << 1) + 1);
            }else {
                dq.push_back(board[idx][j][i]);
            }
        }

        for (int j = n-1; j >= 0; j--)
        {
            if(!dq.empty()) {
                board[idx+1][j][i] = (dq.front() & (~(ll)0x1));
                dq.pop_front();
            }else {
                board[idx+1][j][i] = 0;
            }

            ans = max(ans, board[idx+1][j][i]);
            if(board[idx][j][i] != board[idx+1][j][i]) is_mv = true;
        }
    }

    return is_mv;
}

void printMap(int idx) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[idx][i][j] << " ";
        }
        cout << "\n";
    }
}


void sol(int mv) {
    if(mv >= MAX_M) return ;
    // printMap(mv);

    if(upward(mv)) {
        sol(mv+1);
    }

    if(downward(mv)) {
        sol(mv+1);
    }

    if(right(mv)) {
        sol(mv+1);
    }

    if(left(mv)) {
        sol(mv+1);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[0][i][j];
        }
    }

    sol(0);

    cout << ans << "\n";
    
    return 0;
}