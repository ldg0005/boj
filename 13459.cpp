#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans;
char map[11][11];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
bool first;

void printTest() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
bool safe(int h, int w) {
	return h >= 0 && h < N&&w >= 0 && w < M;
}
void dfs(int _rX, int _rY, int _bX, int _bY, int _cost, int _pre) {
	if (_cost >= ans || _cost >= 10) return;
	int rX = _rX, rY = _rY, bX = _bX, bY = _bY, cost = _cost, pre = _pre;

	if (pre != 2 && pre != 0) {
		bool isR = false, f = true;
		map[bY][bX] = '.';
		while (safe(bY - 1, bX) && map[bY - 1][bX] != '#') {
			if (map[bY - 1][bX] == 'O') {
				f = false;
				bY = _bY;
				break;
			}
			if (map[bY - 1][bX] == 'R') isR = true;
			bY--;
		}
		if (f) {
			if (isR) bY++;
			map[bY][bX] = 'B';
			map[rY][rX] = '.';
			while (safe(rY - 1, rX) && map[rY - 1][rX] != '#') {
				if (map[rY - 1][rX] == 'O') {
					ans = min(cost + 1, ans);
					return;
				}
				if (map[rY - 1][rX] == 'B' && !isR) break;
				rY--;
			}
			map[rY][rX] = 'R';
			if (rY != _rY || rX != _rX || bY != _bY || bX != _bX)
				dfs(rX, rY, bX, bY, cost + 1, 0);
		}
	}

	map[bY][bX] = map[rY][rX] = '.';
	rX = _rX, rY = _rY, bX = _bX, bY = _bY, cost = _cost, pre = _pre;
	map[bY][bX] = 'B', map[rY][rX] = 'R';
	if (pre != 0 && pre != 2) {
		bool isR = false, f = true;
		map[bY][bX] = '.';
		while (safe(bY + 1, bX) && map[bY + 1][bX] != '#') {
			if (map[bY + 1][bX] == 'O') {
				f = false;
				bY = _bY;
				break;
			}
			if (map[bY + 1][bX] == 'R') isR = true;
			bY++;
		}
		if (f) {
			if (isR) bY--;
			map[bY][bX] = 'B';
			map[rY][rX] = '.';
			while (safe(rY + 1, rX) && map[rY + 1][rX] != '#') {
				if (map[rY + 1][rX] == 'O') {
					ans = min(cost + 1, ans);
					return;
				}
				if (map[rY + 1][rX] == 'B' && !isR) break;
				rY++;
			}
			map[rY][rX] = 'R';
			if (rY != _rY || rX != _rX || bY != _bY || bX != _bX)
				dfs(rX, rY, bX, bY, cost + 1, 2);
		}
	}

	map[bY][bX] = map[rY][rX] = '.';
	rX = _rX, rY = _rY, bX = _bX, bY = _bY, cost = _cost, pre = _pre;
	map[bY][bX] = 'B', map[rY][rX] = 'R';
	if (pre != 3 && pre != 1) {
		bool isR = false, f = true;
		map[bY][bX] = '.';
		while (safe(bY, bX + 1) && map[bY][bX + 1] != '#') {
			if (map[bY][bX + 1] == 'O') {
				f = false;
				bX = _bX;
				break;
			}
			if (map[bY][bX + 1] == 'R') isR = true;
			bX++;
		}
		if (f) {
			if (isR) bX--;
			map[bY][bX] = 'B';
			map[rY][rX] = '.';
			while (safe(rY, rX + 1) && map[rY][rX + 1] != '#') {
				if (map[rY][rX + 1] == 'O') {
					ans = min(cost + 1, ans);
					return;
				}
				if (map[rY][rX + 1] == 'B' && !isR) break;
				rX++;
			}
			map[rY][rX] = 'R';
			if (rY != _rY || rX != _rX || bY != _bY || bX != _bX)
				dfs(rX, rY, bX, bY, cost + 1, 1);
		}
	}

	map[bY][bX] = map[rY][rX] = '.';
	rX = _rX, rY = _rY, bX = _bX, bY = _bY, cost = _cost, pre = _pre;
	map[bY][bX] = 'B', map[rY][rX] = 'R';
	if (pre != 3 && pre != 1) {
		bool isR = false, f = true;
		map[bY][bX] = '.';
		while (safe(bY, bX - 1) && map[bY][bX - 1] != '#') {
			if (map[bY][bX - 1] == 'O') {
				f = false;
				bX = _bX;
				break;
			}
			if (map[bY][bX - 1] == 'R') isR = true;
			bX--;
		}
		if (f) {
			if (isR) bX++;
			map[bY][bX] = 'B';
			map[rY][rX] = '.';
			while (safe(rY, rX - 1) && map[rY][rX - 1] != '#') {
				if (map[rY][rX - 1] == 'O') {
					ans = min(cost + 1, ans);
					return;
				}
				if (map[rY][rX - 1] == 'B' && !isR) break;
				rX--;
			}
			map[rY][rX] = 'R';
			if (rY != _rY || rX != _rX || bY != _bY || bX != _bX)
				dfs(rX, rY, bX, bY, cost + 1, 3);
		}
	}
	map[bY][bX] = map[rY][rX] = '.';
	rX = _rX, rY = _rY, bX = _bX, bY = _bY, cost = _cost, pre = _pre;
	map[bY][bX] = 'B', map[rY][rX] = 'R';
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	ans = 987654321;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	int rX, rY, bX, bY;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'R') rX = j, rY = i;
			else if (map[i][j] == 'B') bX = j, bY = i;
		}
	dfs(rX, rY, bX, bY, 0, 5);

	if (ans == 987654321) cout << "0" << '\n';
	else cout << "1" << '\n';

	return 0;
}