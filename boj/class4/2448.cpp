#include <iostream>

using namespace std;

char tree[3072][6143];

void draw(int r, int c) {
    tree[r][c] = '*';
    tree[r+1][c-1] = tree[r+1][c+1] = '*';
    for (int i = c-2; i <= c+2; i++)
    {
        tree[r+2][i] = '*';
    }
    
}

void solve(int n, int r, int c) {
    if(n == 3) {
        draw(r, c);
        return ;
    }

    int next = n / 2; 
    solve(next, r, c);
    solve(next, r+next, c-next);
    solve(next, r+next, c+next);
} 

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            tree[i][j] = ' ';
        }
    }

    solve(n, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2*n - 1; j++)
        {
            cout << tree[i][j];
        }
        cout << "\n";
    }

    return 0;
}

/*
  *
 * *
*****
*/