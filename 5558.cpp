#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int H, W, N, sx, sy, ans;
char map[1001][1001];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int visit[1000][1000];

inline bool safe(int h, int w) {
	return h >= 0 && h < H&&w >= 0 && w < W;
}
void bfs(int find) {
	int cost = 0;
	queue<pair<pair<int,int>, int> > q;
	q.push(make_pair(make_pair(sy, sx), cost));
	visit[sy][sx] = find;
	while (!q.empty()) {
		int h = q.front().first.first;
		int w = q.front().first.second;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int he = h + dy[i];
			int wi = w + dx[i];
			if (safe(he, wi) && map[he][wi] != 'X' && visit[he][wi] != find) {
				if (map[he][wi] - '0' == find) {
					ans += c + 1;
					sy = he, sx = wi;
					return;
				}
				visit[he][wi] = find;
				q.push(make_pair(make_pair(he, wi), c+1));
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int maxnum = 0;
	cin >> H >> W >> N;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S')
				sy = i, sx = j;
		}
	for (int i = 1; i <= N; i++) {
		bfs(i);
	}
	cout << ans << '\n';

	return 0;
}