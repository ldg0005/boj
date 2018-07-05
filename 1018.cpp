#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, ans;
bool map[51][51];
bool comp[16][8] = {
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
	1,0,1,0,1,0,1,0,
	0,1,0,1,0,1,0,1,
};

int solve(int h, int w) {
	int ret = 0, ret1=0;
	for (int i = h; i <h+8; i++) {
		for (int j = w; j < w+8; j++) {
			if (map[i][j] != comp[i - h][j - w]) ret++;
			if (map[i][j] != comp[i - h + 8][j - w]) ret1++;
		}
	}
	return min(ret,ret1);
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	char tmp;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> tmp;
			if (tmp == 'W') 
				map[i][j] = 1;
		}
	int n = N - 8 + 1, m = M - 8 + 1;
	ans = 987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = min(ans, solve(i,j));
		}
	}
	cout << ans << '\n';

	return 0;
}