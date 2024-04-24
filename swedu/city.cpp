#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보
bool visited[20][20];

// 4개로 2개 이상 뽑는 경우의 수
// 2^4 = 16 - 4 = 12

int pipe[12] = { 0, 5, 10, 12, 9, 3, 6, 14, 13, 11, 7, 15};
const int DIR = 4;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool isIn(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

void Input_Data(void){
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++){
		cin >> str;
		for(int j = 0; j < N; j++){
			if(str[j] < 'A') map[i][j] = str[j] - '0';
			else map[i][j] = str[j] - 'A' + 10;
		}
	}
}

void Solve() {
    queue<pair<int, int> > que;
    
    que.push({Y, X});
    visited[Y][X] = true;

    // BFS vs DFS??
    int r, c;
    while (!que.empty())
    {
        tie(r, c) = que.front();
        que.pop();

        int p = pipe[map[r][c]];
        // cout << "r : " << r << " c : " << c << " p : " << p <<"\n";

        for (int i = 0; i < DIR; i++)
        {
            if(!(p & (1 << i))) continue;
            // cout << "i : " << i << "\n";

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(!isIn(nr, nc) || visited[nr][nc]) continue;

            int nextCh = (i >= 2 ? i-2 : i+2);
            int np = pipe[map[nr][nc]];
            // cout << "ch : " << nextCh << " np : " << np << "\n";

            if(np & (1 << nextCh)) {
                visited[nr][nc] = true;
                que.push({nr, nc});
            }
        }   
    }
}

int Count() {
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(!visited[i][j] && map[i][j] != 0) ret++;
        }
    }
    return ret;
}

int main(){
    // freopen("input.txt", "r", stdin);
	int ans;
	Input_Data();		//	입력 함수

	//	코드를 작성하세요
    Solve();
    ans = Count();
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
