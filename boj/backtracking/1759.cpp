#include <iostream>
#include <algorithm>

using namespace std;

int L, C;
char arr[26];
char ans[26];

void DFS(int d, int cnt, int idx) {
    if(d == L) {
        if(cnt >= 1 && L-cnt >= 2) {
            for (int i = 0; i < L; i++)
            {
                cout << ans[i];
            }
            cout <<"\n";
        }

        return ;
    }

    if(idx == C) return;

    for (int i = idx; i < C; i++)
    {
        ans[d] = arr[i];
        if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
            DFS(d+1, cnt+1, i+1);            
        }else {
            DFS(d+1, cnt, i+1);
        }
    }
}

int main() {
    cin >> L >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+C);

    DFS(0, 0, 0);   

    return 0;
}