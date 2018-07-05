#include <iostream>
#include <vector>
using namespace std;

int N, M, H, ans;
vector<vector<int> > map, tmp;
bool f;

bool chk() {
	for (int n = 1; n <= N; n++) {
		int nn = n;
		for (int i = 1; i <= H; i++) 
			nn = map[i][nn];
		if (nn != n) return false;
	}
	return true;
}
void dfs(int depth, int n, int h, int end) {
	if (depth == end) {
		if (chk()) {
			ans = depth;
			f = true;
		}
		return;
	}
	for (int i = n; i < N; i++) {
		for (int j = h; j <= H; j++) {
			if (map[j][i] == i && map[j][i+1]==i+1) {
				map[j][i] = i + 1;
				map[j][i + 1] = i;
				if (j == H) dfs(depth + 1, n + 1, 1, end);
				else dfs(depth + 1, n, h + 1, end);
				map[j][i] = i;
				map[j][i + 1] = i + 1;
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> H;
	map.resize(H + 1, vector<int>(N + 1));
	tmp.resize(H + 1, vector<int>(N + 1));
	for (int i = 1; i <= H; i++)
		for (int j = 1; j <= N; j++)
			map[i][j] = tmp[i][j] = j;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = tmp[a][b] = b + 1;
		map[a][b + 1] = tmp[a][b + 1] = b;
	}
	for (int c = 0; c <= 3; c++) {
		map = tmp;
		dfs(0, 1, 1, c);
		if (f) {
			cout << c << '\n';
			return 0;
		}
	}
	cout << "-1" << '\n';

	return 0;
}