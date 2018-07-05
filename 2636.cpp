#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool map[100][100], _map[100][100];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
bool chk(int h, int w) {
	for (int i = 0; i < 4; i++) {
		int he = h + dy[i];
		int wi = w + dx[i];
		if (safe(he, wi) && !map[he][wi] && _map[he][wi])
			return true;
	}
	return false;
}
void prec(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y,x));
	_map[y][x] = true;
	while (!q.empty()) {
		int h = q.front().first;
		int w = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int he = h + dy[i];
			int wi = w + dx[i];
			if (safe(he, wi) && !map[he][wi] && !_map[he][wi]) {
				_map[he][wi] = true;
				q.push(make_pair(he, wi));
			}
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int count = 0, cnt=0, num=0, idx=0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j]) num++;
		}
	prec(0,0);
	while (1) {
		bool check[100][100] = { 0, };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && chk(i, j)) {
					check[i][j] = true;
				}
			}
		}
		count = 0;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if (check[i][j]) {
					map[i][j] = false;
					prec(i, j);
					_map[i][j] = true;
					count++,cnt++;
				}
		idx++;
		if (cnt == num) break;
	}
	cout << idx << '\n';
	cout << count << '\n';


	return 0;
}