#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Coordinate {
	int x, y, h, cost;
	Coordinate(int hh, int yy, int xx, int ccost) { h = hh, y = yy, x = xx, cost = ccost; }
};
int dx[6] = { 0,1,0,-1, 0, 0 }, dy[6] = { -1,0,1,0, 0, 0 }, dh[6] = { 0, 0,0,0,-1,1 };
int M, N, H, zero, ans;
int map[101][101][101];
vector<Coordinate> st;

bool safe(int y, int x, int h) {
	return y >= 0 && y < N&&x >= 0 && x < M&&h>=0&&h<H;
}
void solve() {
	queue<Coordinate> q;
	Coordinate tmp(0,0,0,0);
	for (int i = 0; i < st.size(); i++) {
		tmp.h = st[i].h, tmp.y = st[i].y, tmp.x = st[i].x, tmp.cost = 0;
		q.push(tmp);
	}
	while (!q.empty()) {
		int h = q.front().h;
		int y = q.front().y;
		int x = q.front().x;
		int cost = q.front().cost;
		ans < cost ? ans = cost : ans = ans;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int hh = h + dh[i];
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (safe(yy, xx, hh) && map[hh][yy][xx] == 0) {
				Coordinate tt(hh, yy, xx, cost + 1);
				q.push(tt);
				map[hh][yy][xx] = 1;
				zero--;
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H; 
	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				cin >> map[k][i][j];
				Coordinate tmp(0,0,0,0);
				tmp.h = k, tmp.y = i, tmp.x = j, tmp.cost = 0;
				if (map[k][i][j] == 0) zero++;
				else if (map[k][i][j] == 1) st.push_back(tmp);
			}
	solve();

	if (zero == 0) cout << ans << '\n';
	else cout << "-1" << '\n';

	return 0;
}