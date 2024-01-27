#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() 
{
    // freopen("input.txt", "r", stdin);
    string str;
    cin >> str;

    stack<char> s;
    string ans = "";

    for (int i = 0; i < str.size(); i++)
    {
        char cur = str[i];
        char top;

        if(cur ==  '+' || cur ==  '-' ) {
            while (!s.empty() && s.top() != '(')
            {
                ans += s.top();
                s.pop();
            }
            s.push(cur);
        }else if(cur == '*' || cur == '/'){
            while (!s.empty() && (s.top() == '*' || s.top() == '/'))
            {
                ans += s.top();
                s.pop();
            }
            s.push(cur);
        }else if(cur == '(') {
            s.push(cur);
        }else if(cur == ')') {
            while (!s.empty() && s.top() != '(')
            {
                ans += s.top();
                s.pop();
            }
            s.pop();
        }else {
            ans += cur;
        }
    }

    while (!s.empty())
    {
        ans += s.top();
        s.pop();
    }
    
    cout << ans << "\n";

    return 0;
}