#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ans;
char map[21][21];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];

	queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push(make_pair(make_pair(0,0), make_pair(1, (1<<(map[0][0]-'A')))));
	while (!q.empty()) {
		int h = q.front().first.first;
		int w = q.front().first.second;
		int cost = q.front().second.first;
		int chk = q.front().second.second;
		ans = max(ans, cost);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int he = h + dy[i];
			int wi = w + dx[i];
			if (safe(he, wi) && (chk & (1 << (map[he][wi] - 'A'))) == 0) {
				q.push(make_pair(make_pair(he, wi), make_pair(cost + 1, chk | (1 << (map[he][wi] - 'A')))));
			}
		}
	}
	
	cout << ans << '\n';


	return 0;
}