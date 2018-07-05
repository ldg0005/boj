#include <iostream>
#include <queue>
using namespace std;

int N, K, L;
int map[102][102], sec[102];
char dir[102];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	cin >> K;
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> sec[i] >> dir[i];
	map[1][1] = 2;
	for (int i = 0; i <= N + 1; i++) map[0][i] = map[N+1][i] = map[i][0] = map[i][N+1] = 2;
	
	int ans = 1, curl = 0, headdir = 1, taildir = 1, heady = 1, headx = 1, taily = 1, tailx = 1;
	queue<pair<pair<int, int>, int>> q;
	while (1) {
		if (map[heady + dy[headdir]][headx + dx[headdir]] == 2) break;
		if (map[heady + dy[headdir]][headx + dx[headdir]] == 1) {
			heady += dy[headdir];
			headx += dx[headdir];
			map[heady][headx] = 2;
		}
		else {
			heady += dy[headdir];
			headx += dx[headdir];
			map[heady][headx] = 2;
			map[taily][tailx] = 0;
			if (!q.empty() && q.front().first.first == taily && q.front().first.second == tailx) {
				taildir = q.front().second;
				q.pop();
			}
			taily += dy[taildir];
			tailx += dx[taildir];
		}
		if (ans == sec[curl]) {
			if(dir[curl]=='D') headdir = (headdir + 1) % 4;
			else if (dir[curl] == 'L') headdir = (headdir + 3) % 4;
			q.push(make_pair(make_pair(heady, headx), headdir));
			curl++;
		}
		ans++;
	}
	/*for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++)
			cout << map[i][j];
		cout << endl;
	}
	cout << endl;*/
	cout << ans << '\n';

	return 0;
}