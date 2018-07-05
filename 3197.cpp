#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, ll, rr;
char map[1501][1501];
int L[2][2];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int dp[1501][1501];
int visit[1501][1501];

bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
void prec(int idx) {
	queue<pair<pair<int, int>, int> > q;
	for (int i = 0; i<N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '.' || map[i][j] == 'L') {
				q.push({ { i,j },0 });
				visit[i][j] = idx;
			}
		}
	while (!q.empty()) {
		int h = q.front().first.first;
		int w = q.front().first.second;
		int c = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int he = h + dy[k];
			int wi = w + dx[k];
			if (safe(he, wi) && visit[he][wi] != idx) {
				q.push({ { he,wi }, c + 1 });
				dp[he][wi] = c + 1;
				visit[he][wi] = idx;
				rr = max(rr, c + 1);
			}
		}
	}
}
bool check(int mid, int idx) {
	queue<pair<int, int> > q;
	q.push({ L[0][0],L[0][1] });
	visit[L[0][0]][L[0][1]] = idx;
	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		if (h == L[1][0] && w == L[1][1])
			return true;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int he = h + dy[i];
			int wi = w + dx[i];
			if (safe(he, wi) && dp[he][wi] <= mid && visit[he][wi] != idx) {
				visit[he][wi] = idx;
				q.push({ he,wi });
			}
		}
	}
	return false;
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int lidx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				L[lidx][0] = i;
				L[lidx++][1] = j;
			}
		}
	}
	int ans = 0, idx = 1;
	prec(idx);
	idx++;
	while (ll <= rr) {
		int mid = (ll + rr) >> 1;
		if (check(mid, idx)) {
			ans = mid;
			rr = mid - 1;
		}
		else ll = mid + 1;
		idx++;
	}
	cout << ans << '\n';

	return 0;
}