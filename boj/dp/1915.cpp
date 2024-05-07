#include <iostream>

#define MAX_NM  1000

using namespace std;

bool board[MAX_NM][MAX_NM][MAX_NM];
int n, m;

int main() {
    cin >> n >> m;

    char c;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> c;
            board[0][i][j] = (c == '1');
        }
    }


    return 0;
}