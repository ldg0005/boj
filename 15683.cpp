#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, zerocnt, ans;
vector<vector<int> > map;
vector<pair<int, int> > loca;
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };

bool safe(int y, int x) {
	return y >= 0 && y < N&&x >= 0 && x < M;
}
void dfs(int depth, int cur) {
	if (depth == loca.size()) {
		ans = min(ans, zerocnt - cur);
		return;
	}
	int y = loca[depth].first, x = loca[depth].second;
	if (map[y][x] == 1) {
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i], xx = x + dx[i], cnt=0;
			vector<vector<int> > tmp(map);
			while (safe(yy, xx) && map[yy][xx] != 6) {
				if (map[yy][xx] == 0) {
					cnt++;
					map[yy][xx] = map[y][x];
				}
				yy += dy[i], xx += dx[i];
			}
			dfs(depth + 1, cur + cnt);
			map = tmp;
		}
	}
	else if (map[y][x] == 2) {
		for (int i = 0; i < 2; i++) {
			int yy = y + dy[i], xx = x + dx[i], cnt = 0;
			int yyy = y + dy[i + 2], xxx = x + dx[i + 2];
			vector<vector<int> > tmp(map);
			while (safe(yy, xx) && map[yy][xx] != 6) {
				if (map[yy][xx] == 0) {
					cnt++;
					map[yy][xx] = map[y][x];
				}
				yy += dy[i], xx += dx[i];
			}
			while (safe(yyy, xxx) && map[yyy][xxx] != 6) {
				if (map[yyy][xxx] == 0) {
					cnt++;
					map[yyy][xxx] = map[y][x];
				}
				yyy += dy[i+2], xxx += dx[i+2];
			}
			dfs(depth + 1, cur + cnt);
			map = tmp;
		}
	}
	else if (map[y][x] == 3) {
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i], xx = x + dx[i], cnt = 0;
			int yyy = y + dy[(i + 1)%4], xxx = x + dx[(i + 1)%4];
			vector<vector<int> > tmp(map);
			while (safe(yy, xx) && map[yy][xx] != 6) {
				if (map[yy][xx] == 0) {
					cnt++;
					map[yy][xx] = map[y][x];
				}
				yy += dy[i], xx += dx[i];
			}
			while (safe(yyy, xxx) && map[yyy][xxx] != 6) {
				if (map[yyy][xxx] == 0) {
					cnt++;
					map[yyy][xxx] = map[y][x];
				}
				yyy += dy[(i + 1) % 4], xxx += dx[(i + 1) % 4];
			}
			dfs(depth + 1, cur + cnt);
			map = tmp;
		}
	}
	else if (map[y][x] == 4) {
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i], xx = x + dx[i], cnt = 0;
			int yyy = y + dy[(i + 1) % 4], xxx = x + dx[(i + 1) % 4];
			int yyyy = y + dy[(i + 2) % 4], xxxx = x + dx[(i + 2) % 4];
			vector<vector<int> > tmp(map);
			while (safe(yy, xx) && map[yy][xx] != 6) {
				if (map[yy][xx] == 0) {
					cnt++;
					map[yy][xx] = map[y][x];
				}
				yy += dy[i], xx += dx[i];
			}
			while (safe(yyy, xxx) && map[yyy][xxx] != 6) {
				if (map[yyy][xxx] == 0) {
					cnt++;
					map[yyy][xxx] = map[y][x];
				}
				yyy += dy[(i + 1) % 4], xxx += dx[(i + 1) % 4];
			}
			while (safe(yyyy, xxxx) && map[yyyy][xxxx] != 6) {
				if (map[yyyy][xxxx] == 0) {
					cnt++;
					map[yyyy][xxxx] = map[y][x];
				}
				yyyy += dy[(i + 2) % 4], xxxx += dx[(i + 2) % 4];
			}
			dfs(depth + 1, cur + cnt); 
			map = tmp;
		}
	}
	else if (map[y][x] == 5) {
		int cnt = 0;
		vector<vector<int> > tmp = map;
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i], xx = x + dx[i];
			while (safe(yy, xx) && map[yy][xx] != 6) {
				if (map[yy][xx] == 0) {
					cnt++;
					map[yy][xx] = map[y][x];
				}
				yy += dy[i], xx += dx[i];
			}
		}
		dfs(depth + 1, cur + cnt);
		map = tmp;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	map.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j]!=6)
				loca.push_back({ i,j });
			else if (map[i][j] == 0) zerocnt++;
		}
	ans = 987654321;
	dfs(0, 0);
	cout << ans << '\n';

	return 0;
}