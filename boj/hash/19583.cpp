#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S, E, Q;
    cin >> S >> E >> Q;

    int s = 60*stoi(S.substr(0, 2)) + stoi(S.substr(3, 2));
    int e = 60*stoi(E.substr(0, 2)) + stoi(E.substr(3, 2));
    int q = 60*stoi(Q.substr(0, 2)) + stoi(Q.substr(3, 2));

    string time, nick;

    unordered_set<string> mapper;
    int ans = 0;

    while (!cin.eof())
    {
        cin >> time >> nick;

        int t = 60*stoi(time.substr(0, 2)) + stoi(time.substr(3, 2));

        if(t <= s) {
            mapper.insert(nick);
            continue;
        }

        if(t >= e && t <= q) {
            if(mapper.find(nick) != mapper.end()) {
                mapper.erase(nick);
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}