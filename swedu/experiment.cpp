#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int N;//후보자 수
pair<int, int> A[100000 + 10];//기질 값
const int INF = 2e9+7;

// two pointer 로 해결이 가능할 듯

void InputData(){
	cin >> N;
    int a;
	for (int i = 0; i < N; i++) {
        cin >> a;
        A[i] = {a, i};
    }

    sort(A, A+N);
}

int main(){
    // freopen("input.txt", "r", stdin);
	InputData();//	입력 함수

	//	코드를 작성하세요
    int gap = INF;
    pair<int, int> ans = {1e5, 1e5};

    int i = 0, j = N-1;

    while (i != j)
    {
        int iv, iat, jv, jat;
        tie(iv, iat) = A[i];
        tie(jv, jat) = A[j];

        int sum = iv + jv;

        if(gap > abs(sum)) {
            gap = abs(sum);
            if(iat < jat) ans = {iat, jat};
            else ans = {jat, iat};
        }else if(gap == abs(sum)) {
            int ai = min(jat, iat);
            int aj = max(jat, iat);
            if(ans.first > ai) ans = {ai, aj};
        }

        if(sum > 0) j--;
        else i++;
    }
    

	cout << ans.first << " " << ans.second << "\n";
	
	return 0;
}
