#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int l_cnt = 0;
    int r_cnt = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == '1') {
            l_cnt++;
            while (i+1 < str.size() && str[i+1] == '1')
            {
                i++;
            }
        }else {
            r_cnt++;
            while (i+1 < str.size() && str[i+1] == '0')
            {
                i++;
            }
        }
    }
    
    cout << min(l_cnt, r_cnt) << endl;

    return 0;
}