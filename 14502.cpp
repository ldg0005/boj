#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, num0, num2, ans;
int map[9][9];
bool visited[9][9];
int loca2[10][2];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, 1, 0, -1 };

bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
int cal2() {
	int ret = 0;
	int tmpmap[9][9] = { 0, };
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) tmpmap[i][j] = map[i][j];
	queue<pair<int,int>> q;
	for(int i=0;i<num2;i++)
		q.push(make_pair(loca2[i][0], loca2[i][1]));
	while (!q.empty()) {
		int height = q.front().first;
		int width = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int he = height + dy[i];
			int wi = width + dx[i];
			if (safe(he, wi) && !tmpmap[he][wi]) {
				q.push(make_pair(he, wi));
				tmpmap[he][wi] = 2;
				ret++;
			}
		}
	}
	return ret;
}
void dfs(int depth, int sy, int sx) {
	if (depth == 3) {
		int tmp = cal2();
		ans = max(ans, num0 - tmp);
		return;
	}
	for(int i=0;i<N;i++)
		for (int j = sx; j < M; j++) {
			if (!map[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				map[i][j] = 1;
				dfs(depth + 1, i, j);
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) num0++;
			else if (map[i][j] == 2) {
				loca2[num2][0] = i, loca2[num2][1] = j;
				num2++;
			}
		}
	num0 -= 3;
	dfs(0,0,0);
	cout << ans << '\n';

	return 0;
}