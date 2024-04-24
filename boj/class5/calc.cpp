#include <iostream>

using namespace std;

using ll = long long;

int N;//테스트 케이스 수
int B;//진법
char S[110];//첫 번째 정수
char D[110];//두 번째 정수

void InputData(){
	cin >> B >> S >> D;
}
int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		InputData();//입력 함수
		//	코드를 작성하세요
		
		ll s = 0, d = 0;
		bool s_odd = false, d_odd = false;
        
        if(S[0] == '-') s_odd = true;
		for (int j = 1; j < strlen(S); j++)
        {
        }
        
	}
	return 0;
}