#include <iostream>
#include <string>
#include <stack>

using namespace std;

const int MAX_SIZE = 1000;

int map[MAX_SIZE+1][MAX_SIZE+1];

int main() {
    // freopen("input.txt", "r", stdin);

    string s1, s2;

    cin >> s1 >> s2;
    int s1_size = (int)s1.size(), s2_size = (int)s2.size();

    for (int i = 1; i <= s2_size; i++)
    {
        for (int j = 1; j <= s1_size; j++)
        {
            if(s1[j-1] == s2[i-1]) map[i][j] = map[i-1][j-1] + 1;
            else map[i][j] = max(map[i][j-1], map[i-1][j]);
        }
    }

    int col = s1_size, row = s2_size;
    stack<char> stacks;

    // for (int i = 1; i <= s2_size; i++)
    // {
    //     for (int j = 1; j <= s1_size; j++)
    //     {
    //         cout << map[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while (col != 0 && row != 0)
    {
        // cout << row << " " << col << "\n";
        if(map[row][col] == map[row][col-1]) {
            col--;
        }else if(map[row][col] == map[row-1][col]) row--;
        else {
            row--;
            col--;
            stacks.push(s2[row]);
        }
    }

    string ans = "";
    while (!stacks.empty())
    {
        ans += stacks.top();
        stacks.pop();
    }
    
    
    cout << map[s2_size][s1_size] << "\n" << ans << "\n";

    return 0;
}