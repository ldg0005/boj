#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, ans;
bool button[1000001], bot[11];
vector<int> st;

bool chk(int n) {
	while (1) {
		if (n > 9) {
			int a = n % 10;
			if (bot[a]) return false;
			n /= 10;
		}
		else {
			if (bot[n]) return false;
			else return true;
		}
	}
}
void prec() {
	for (int i = 0; i < 1000000; i++) {
		if (!chk(i)) button[i] = true;
	}
}
int cal(int n) {
	int ret = 0;
	while (1) {
		if (n > 9) {
			ret++;
			n /= 10;
		}
		else {
			return ret + 1;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		bot[a] = true;
	}
	ans = N - 100 >= 0 ? N-100 : 100-N;
	prec();
	int up = N, down = N;
	while (button[up] && button[down]) {
		up++;
		if (down - 1 >= 0) down--;
	}
	if (!button[up]) {
		int cnt = cal(up);
		ans = up - N + cnt < ans ? up - N + cnt : ans;
	}
	if (!button[down]) {
		int cnt = cal(down);
		ans = N - down + cnt < ans ? N - down + cnt : ans;

	}
	
	cout << ans << '\n';
	
	return 0;
}