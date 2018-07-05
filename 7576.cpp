#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = { 0,1,0,-1 }, dy[4] = { -1,0,1,0 };
int M, N, zero, ans;
vector<vector<int> > map;
vector<pair<int, int> > st;

bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
void solve() {
	queue<pair<pair<int, int>, int> > q;
	for (int i = 0; i < st.size(); i++) 
		q.push({ {st[i].first, st[i].second},0 });
	while (!q.empty()) {
		int h = q.front().first.first;
		int w = q.front().first.second;
		int cost = q.front().second;
		ans < cost ? ans = cost : ans = ans;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int hh = h + dy[i];
			int ww = w + dx[i];
			if (safe(hh, ww) && map[hh][ww] == 0) {
				q.push({ {hh,ww},cost + 1 });
				map[hh][ww] = 1;
				zero--;
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	map.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zero++;
			else if (map[i][j] == 1) st.push_back({ i,j });
		}
	solve();
	
	if(zero==0) cout << ans << '\n';
	else cout << "-1" << '\n';

	return 0;
}