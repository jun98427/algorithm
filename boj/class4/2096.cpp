#include <iostream>

#define MAX_N   100000

using namespace std;

int tmp1[3], tmp2[3];
int n;

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;

    int a, b, c, a1, b1, c1;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;

        if(i == 0) {
            tmp1[0] = tmp2[0] = a;
            tmp1[1] = tmp2[1] = b;
            tmp1[2] = tmp2[2] = c;
        }else {
            a1 = max(tmp1[0], tmp1[1]);
            b1 = max(a1, tmp1[2]);
            c1 = max(tmp1[1], tmp1[2]);

            tmp1[0] = a1 + a;
            tmp1[1] = b1 + b;
            tmp1[2] = c1 + c;

            a1 = min(tmp2[0], tmp2[1]);
            b1 = min(a1, tmp2[2]);
            c1 = min(tmp2[1], tmp2[2]);

            tmp2[0] = a1 + a;
            tmp2[1] = b1 + b;
            tmp2[2] = c1 + c;
        }
    }

    int max_val = max(tmp1[0], max(tmp1[1], tmp1[2]));
    int min_val = min(tmp2[0], min(tmp2[1], tmp2[2]));
    
    cout << max_val << " " << min_val << "\n";

    return 0;
}