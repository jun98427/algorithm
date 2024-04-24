#include <iostream>

using namespace std;

int N;//제품 수
int M;//제품 종류 수
int ID[100000 + 10][10];//제품 ID
int Count[10];
bool finished[10];

void InputData(){
	int i, v;
	cin >> N >> M;
	for(i = 1; i <= N; i++){
		cin >> v;
		Count[v]++;

		for (int j = 1; j <= M; j++)
		{
			ID[i][j] = ID[i-1][j];
			if(j == v) ID[i][j]++;
		}
	}
}

int Solve(int s) {
	// cout << s << "\n";
	int ret = 1e5;
	if(s == N) return 0; 

	for (int i = 1; i <= M; i++)
	{
		if(finished[i]) continue;

		finished[i] = true;
		int next = s + Count[i];
		int mv = Count[i] - ID[next][i] + ID[s][i];
		ret = min(ret, Solve(next) + mv);
		finished[i] = false;
	}

	return ret;
}

int main(){
	// freopen("input.txt", "r", stdin);
	int ans;

	InputData();//입력 함수
	
	//	코드를 작성하세요
	ans = Solve(0);

	cout << ans << endl;
	return 0;
}