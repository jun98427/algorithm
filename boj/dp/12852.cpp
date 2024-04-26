#include <iostream>

#define MAX_N   1'000'000

using namespace std;

int m[MAX_N+1];
int c[MAX_N+1];

void DFS(int cur) {
    // cout << cur << ' ';
    if(cur == 0) {
        return ;
    }else {
        cout << cur << ' ';
        DFS(c[cur]);
    }
}

int main(int argc, const char * argv[]) {
    int n, v;
    cin >> n;
    m[1] = 0;
    
    for(int i=2; i<=n; i++)
    {
        v = m[i-1] + 1;
        c[i] = i-1;

        if(i % 3 == 0)
        {
            if( v > m[i/3] + 1 ) {
                v = m[i/3] + 1;
                c[i] = i/3;
            }
        }
        
        if(i % 2 == 0)
        {
            if(v > m[i/2] + 1) {
                v = m[i/2] + 1;
                c[i] = i / 2;
            }
        }
        m[i] = v;
    }
    
    cout << m[n] << "\n";
    DFS(n);
    cout << '\n';

    return 0;
}
