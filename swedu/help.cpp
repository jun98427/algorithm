#include <iostream>

using namespace std;

int N;//보내려는 물품 개수
int C[10];//BOX 개수(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 순)
int sol[10];//보내는 BOX 개수
int V[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000};
int ans;

// greedy? 
// greedy 가 되는 이유는? -> 모든 것이 배수 관계로 존재한다?

bool Solve(int idx, int remain) 
{
    if(remain == 0) return true;

    if(idx >= 10 || V[idx] > remain) return false;

    if(remain % V[idx] != 0 ) return false;

    int m = min(C[idx], remain / V[idx]);

    bool ret = false;
    for (int i = m; i >= 0; i--)
    {
        sol[idx] = i;
        ans += i;
        ret = Solve(idx+1, remain - i * V[idx]);

        if(ret) 
        {
            // cout << "idx : " << idx << " m : " <<  i << "\n";
            break;
        }

        ans -= i;
    }
    
    return ret;
} 

void InputData(){
	int i;
	cin >> N;
	for(i = 0; i < 10; i++){
		cin >> C[i];
	}
}

void OutputData(int ans){
	int i;
	cout << ans << endl;
	for(i = 0; i < 10; i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
	

	InputData();//	입력 함수

	//	코드를 작성하세요
    Solve(0, N);


	OutputData(ans);//	출력 함수

	return 0;
}