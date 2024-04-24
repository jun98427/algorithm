#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int N;//손님 수
int P[10000 + 10];
priority_queue<pair<int, int> > que;

int findP(int x) {
    if(x == P[x]) return x;
    return P[x] = findP(P[x]);
}

bool Union(int x, int y) {
    int px = findP(x);
    int py = findP(y);

    if(px == py) return false;

    if(px > py) P[px] = py;
    else P[py] = px;

    return true;
}

void InputData(){
	cin >> N;

    int p, t;
	for (int i = 0; i < N; i++){
        cin >> p >> t;
        que.push({p, t});
	}

    for (int i = 1; i <= 10000; i++)
    {
        P[i] = i;
    }
    
}

int main(){
    // freopen("input.txt", "r", stdin);
	int ans = 0;

	InputData();			//	입력 함수

    int p, t;
	while (!que.empty())
    {
        tie(p, t) = que.top();
        que.pop();

        int tp = findP(t);
        if(tp == 0) continue;

        Union(tp, tp-1);
        ans += p;
    }
	
	cout << ans << endl;	//	정답 출력

	return 0;
}
