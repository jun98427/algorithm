#include <iostream>

#define MAX_N   100000
#define MAX_V   1000000

using namespace std;

bool isExist[MAX_V+1];
int scores[MAX_V+1];
int cards[MAX_N];

// 쉽게 하면 O(n ^ 2) -> 시간 초과

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        isExist[val] = true;
        cards[i] = val;
    }

    for (int i = 0; i < n; i++)
    {
        int val = cards[i];
        for (int j = (cards[i] << 1); j <= MAX_V; j += val)
        {
            if(isExist[j]) {
                scores[j]--;
                scores[val]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << scores[cards[i]] << " ";
    }
    cout << "\n";

    return 0;
}