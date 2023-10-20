#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> plus, minus;

    int v1, v2, zero_count=0;
    for (int i = 0; i < n; i++)
    {
        cin >> v1;
        if(v1 > 0) plus.push(v1);
        else if(v1 == 0) zero_count++;
        else {
            minus.push(-v1);
        }
    }

    int ans = 0;

    while (!plus.empty())
    {
        v1 = plus.top();
        plus.pop();

        if(!plus.empty() && v1 != 1){
            v2 = plus.top();
            plus.pop();
            
            if(v2 != 1) ans += v1 * v2;
            else ans += v1 + 1;
        }else {
            ans += v1;
        }
    }

    while (!minus.empty())
    {
        v1 = minus.top();
        minus.pop();

        if(!minus.empty()) {
            v2 = minus.top();
            minus.pop();

            ans += v1 * v2;
        }else {
            if(zero_count == 0) {
                ans -= v1;
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}