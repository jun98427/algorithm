#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void solve(int s, int e) {
    if(s >= e) return ;

    // if (s == e - 1) {
	// 	cout << v[s] << '\n';
	// 	return;
	// }
    
    int l = v[s];

    int idx = s+1;
    while (idx < e)
    {
        if(l < v[idx]) break;
        idx++;
    }
    
    solve(s+1, idx);
    solve(idx, e);
    cout << l << "\n";
}

int main() {
    // freopen("input.txt", "r", stdin);

    int val;
    while (cin >> val)
    {
        v.push_back(val);
    }
    
    solve(0, v.size());

    return 0;
}