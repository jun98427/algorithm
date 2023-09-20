#include <iostream>

using namespace std;

int n;
char str[20];

int calc(int idx, int cur, int next) 
{
    if(str[idx] == '*') return cur * next;
    else if(str[idx] == '+') return cur +next;
    else return cur - next;
}

int solve(int idx, int cur)
{
    if(idx >= n) return cur;

    int next = atoi(&str[idx+1]);
    int ret = solve(idx+2, calc(idx, cur, next));

    if(idx+3 <= n-1) 
    {
        int temp = calc(idx+2, next, atoi(&str[idx+3]));

        ret = max(ret, solve(idx+4, calc(idx, cur, temp)));
    }

    return ret;
}

int main() 
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    int ans = solve(1, atoi(&str[0]));

    cout << ans << endl;

    return 0;
}