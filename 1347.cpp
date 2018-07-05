#include <iostream>
#include <algorithm>
using namespace std;

int N;
char str[50];
bool map[101][101];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> str;
	int dir = 2, curx = 50, cury = 50, sx=50, sy=50, ex=50, ey=50;
	map[cury][curx] = true;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'R') {
			dir++;
			if (dir == 4) dir = 0;
		}
		else if (str[i] == 'L') {
			dir--;
			if (dir == -1) dir = 3;
		}
		else if (str[i] == 'F') {
			cury += dy[dir];
			curx += dx[dir];
			map[cury][curx] = true;
			sx = min(sx, curx);
			sy = min(sy, cury);
			ex = max(ex, curx);
			ey = max(ey, cury);
		}
	}
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			if (map[i][j]) cout << ".";
			else cout << "#";
		}
		cout << '\n';
	}


	return 0;
}