#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
int ans, cnt;

bool safe(int h, int w) {
	return h >= 0 && h < 5 && w >= 0 && w < 9;
}
void dfs(int h, int w, int depth, vector<vector<char> > map) {
	vector<vector<char> > _map(map);
	for (int i = 0; i < 4; i++) {
		int he = h + dy[i];
		int wi = w + dx[i];
		if (safe(he, wi) && _map[he][wi] == 'o') {
			int hh = he + dy[i];
			int ww = wi + dx[i];
			if (safe(hh, ww) && _map[hh][ww] == '.') {
				_map[h][w] = _map[he][wi] = '.';
				_map[hh][ww] = 'o';
				for (int k = 0; k < 5; k++)
					for (int z = 0; z < 9; z++)
						if (_map[k][z] == 'o')
							dfs(k, z, depth + 1, _map);
				_map[h][w] = _map[he][wi] = 'o';
				_map[hh][ww] = '.';
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 9; j++)
			if (_map[i][j] == 'o') count++;
	if (ans > count) {
		ans = count;
		cnt = depth;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		int y, x;
		vector<vector<char> > map(5, vector<char>(9));
		vector<pair<int, int> > p;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 9; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'o') p.push_back({ i,j });
			}
		ans = 987654321;
		for(int i=0;i<p.size();i++)
			dfs(p[i].first, p[i].second, 0, map);
		cout << ans << " " << cnt << '\n';
	}

	return 0;
}