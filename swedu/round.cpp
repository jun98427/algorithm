#include <iostream>
#include <vector>

using namespace std;

int N;//직원 수
int S;//시작 직원 번호
int M;

void InputData(){
	cin >> N >> S >> M;
}

int main(){
    // freopen("input.txt", "r", stdin);

	InputData();//	입력 함수

	//	코드를 작성하세요
    vector<int> v;
    for (int i = 1; i <= N; i++)
    {
        v.push_back(i);
    }

    int cur = N, i = S - 1;
    while (cur)
    {   
        i = (i + M) % cur;
        i--;
        if(i == -1) {
            i = cur -1;
        } 

        cout << v[i] << " ";
        v.erase(v.begin() + i);

        cur--;
    }
    
    cout << "\n";

	return 0;
}