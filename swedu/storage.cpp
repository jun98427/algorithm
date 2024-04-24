#include <iostream>

using namespace std;

int N, M;//공장 수, 도로 정보 수
const int MAX_N = 100;

int Dist[MAX_N+1][MAX_N+1];

void InputData(){
	int i, a, b, d;
	cin >> N >> M;
	for (i = 0; i < M; i++){
		cin >> a >> b >> d;
        Dist[a][b] = d;
        Dist[b][a] = d;
	}

    for (int i = 1; i <= N; i++)
    {
        Dist[i][i] = 0;
    }
}

void Calc() {
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if(i == j) continue;

                if(Dist[i][k] != 0 && Dist[k][j] != 0) {
										if(Dist[i][j] == 0 || Dist[i][j] > Dist[i][k] + Dist[k][j]) 
                    	Dist[i][j] = Dist[i][k] + Dist[k][j];
                }
            }
        }
    }
}

int main(){
	int ans = -1;
	InputData();//	입력 함수

	//	코드를 작성하세요
    Calc();

    for (int i = 1; i <= N; i++)
    {
        int tmp = 0;
        for (int j = 1; j <= N; j++)
        {
            tmp = max(tmp, Dist[i][j]);
        }
        
        if(ans == -1 || tmp < ans) ans = tmp;
    }
    
	
	cout << ans << endl;//	정답 출력

	return 0;
}