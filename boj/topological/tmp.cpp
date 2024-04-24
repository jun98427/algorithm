#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int ans = 0;
    string str;

    cin >> str;

    stack<int> st;
    stack<int> vst;

    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(' || str[i] == '[') {
            
        }
    }


    cout << ans << "\n";

    return 0;    
}