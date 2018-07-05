#include <iostream>
using namespace std;

int N, M;
int map[50][50];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool safe(int h, int w) {
	return h > 0 && h < N - 1 && w>0 && w < M - 1;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	int curx, cury, curdir;
	cin >> cury >> curx >> curdir;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	int cnt = 0, ans=0;
	while (1) {
		if (!map[cury][curx]) {
			map[cury][curx] = 2;
			ans++;
		}
		int tmpdir = (curdir + 3) % 4;
		int tmpy = cury + dy[tmpdir], tmpx = curx + dx[tmpdir];
		if (safe(tmpy,tmpx) && !map[tmpy][tmpx]) {
			curdir = tmpdir;
			cury += dy[curdir];
			curx += dx[curdir];
			cnt = 0;
		}
		else {
			curdir = tmpdir;
			cnt++;
		}
		if (cnt == 4) {
			tmpdir = (curdir + 2) % 4;
			tmpy = cury + dy[tmpdir], tmpx = curx + dx[tmpdir];
			if (safe(tmpy, tmpx) && map[tmpy][tmpx]!=1) {
				cury += dy[tmpdir];
				curx += dx[tmpdir];
				cnt = 0;
			}
			else break;
		}
	}
	cout << ans << '\n';

	return 0;
}