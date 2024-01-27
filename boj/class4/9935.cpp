#include <iostream>
#include <string>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    string str, sub, temp = "";
    cin >> str >> sub;

    int len = sub.size();

    for (int i = 0; i < str.size(); i++)
    {
        temp += str[i];

        if(temp.size() >= sub.size() && temp.back() == sub.back()){
            bool flag = true;

            for (int j = 0; j < len; j++)
            {
                if(temp[temp.size()-len+j] != sub[j]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) temp.erase(temp.size()-len, len);
        }
    }
    

    cout << (temp == "" ? "FRULA" : temp) << "\n";

    return 0;
}