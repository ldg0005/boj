#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, ans;
char map[51][51];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
int dyy[8] = { -1,-1,0,1,1,1,0,-1 };
int dxx[8] = { 0,1,1,1,0,-1,-1,-1 };
int curr, curx, cury;
int endr, endx, endy;
vector<pair<int, int> > B,E;
bool visit[51][51][2];

bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < N;
}
bool canRota(int h, int w) {
	for (int i = 0; i < 8; i++) {
		int he = h + dyy[i];
		int wi = w + dxx[i];
		if (!safe(he, wi) || map[he][wi] == '1')
			return false;
	}
	return true;
}
bool canMove(int h, int w, int r) {
	if (r == 0) {
		if (!safe(h, w - 1) || !safe(h, w) || !safe(h, w + 1) ||
			map[h][w - 1] == '1' || map[h][w] == '1' || map[h][w + 1] == '1')
			return false;
	}
	else {
		if (!safe(h - 1, w) || !safe(h, w) || !safe(h + 1, w) ||
			map[h - 1][w] == '1' || map[h][w] == '1' || map[h + 1][w] == '1')
			return false;
	}
	return true;
}
void bfs() {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push({ { cury,curx },{curr,0} });
	visit[cury][curx][curr] = true;
	while (!q.empty()) {
		int h = q.front().first.first;
		int w = q.front().first.second;
		int r = q.front().second.first;
		int c = q.front().second.second;
		if (h == endy && w == endx && r == endr) {
			ans = c;
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int he = h + dy[i];
			int wi = w + dx[i];
			if (canMove(he, wi, r) && !visit[he][wi][r]) {
				visit[he][wi][r] = true;
				q.push({ {he,wi},{r,c + 1} });
			}
		}
		if (canRota(h, w) && !visit[h][w][r ^ 1]) {
			r ^= 1;
			visit[h][w][r] = true;
			q.push({ {h,w},{r,c + 1} });
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B')
				B.push_back({ i,j });
			else if (map[i][j] == 'E')
				E.push_back({ i,j });
		}
	B[0].first == B[1].first ? curr = 0 : curr = 1;
	E[0].first == E[1].first ? endr = 0 : endr = 1;
	cury = B[1].first, curx = B[1].second;
	endy = E[1].first, endx = E[1].second;
	bfs();
	cout << ans << '\n';

	return 0;
}