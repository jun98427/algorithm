#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int N;				//	필터 한 변의 크기
int L;				//	LED의 범위(길이) 
int M;				//	살균대상의 개수
int sol;			//	정답
int board[10001][10001];
vector<pair<int, int> > loc;

// 잘못 생각한 점은 무엇일까?
// 모든 경우를 생각하지 않아도 될 듯 -> 곰팡이가 있는 곳을 경계로 시작할 수 있음
// 다만 문제는 이 경우, 4 방향 모두 조사해야함 -> 100 * 4 * 50
// 모든 점에서 부터 시작할 경우 -> 10000 * 10000 * 50

void Input(void){
    int r, c;
	cin >> N >> L >> M;
	for (int i = 0; i < M; i++) 
    {
        cin >> r >> c;
        loc.push_back({r, c});
        board[r][c] = 1;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
        }
    }
}

int Calc(int sr, int sc, int er, int ec) {
    return board[er][ec] - board[er][sc] - board[sr][ec] + board[sr][sc];
}

void Solve() {
    int r, c;
    for (pair<int,int> l : loc)
    {
        tie(r, c) = l;
        int ret = 0;
        // 1 사분면
        int sr = max(0, r - L + 1);
        for (int i = sr; i < r; i++)
        {
            int sc = max(0, c - L + i);
            ret = max(ret, Calc(sr, sc, r, c));
        }

        // 2 사분면
        for (int i = sr; i < r; i++)
        {
            int ec = min(M, c + L - i);
            ret = max(ret, Calc(sr, c, r, ec));
        }
        
        // 3 사분면
        int er = min(N, r + L - 1);
        for (int i = er; i > r; i--)
        {
            int ec = min(M, c + L - i);

        }
        

        // 4 사분면
    }
    
}

int main(void){
	freopen("input.txt", "r", stdin);
	Input();

    L /= 2;
	//	코드를 작성하세요
    Solve();
    

	//	정답출력
	printf("%d\n", sol);

	return 0;
}