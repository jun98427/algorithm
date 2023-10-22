#include <iostream>
#include <string>
#include <map>

using namespace std;

int test_case;

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> test_case;

    while (test_case--)
    {
        int n;
        cin >> n;

        string name, type;

        map<string, int> mapper;

        for (int i = 0; i < n; i++)
        {
            cin >> name >> type;
            mapper[type]++;
        }
        
        long long ans = 1;

        for (auto it : mapper)
        {
            ans = ans * (it.second + 1);
        }

        ans -= 1;
        
        cout << ans << endl;
    }

    return 0;
}