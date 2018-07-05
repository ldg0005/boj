#include <iostream>
#include <vector>
using namespace std;

int N, x,y,d,g,ans;
bool map[101][101];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
vector<int> st;

bool safe(int y, int x) {
	return y >= 0 && y < 101 && x >= 0 && x < 101;
}
bool chk(int y, int x) {
	if (safe(y, x) && map[y][x])
		if (safe(y + 1, x) && map[y + 1][x])
			if (safe(y, x + 1) && map[y][x + 1])
				if (safe(y + 1, x + 1) && map[y + 1][x + 1])
					return true;
	return false;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int t = 0; t < N; t++) {
		cin >> x >> y >> d >> g;
		st.clear();
		map[y][x] = map[y+dy[d]][x+dx[d]] = true;
		y += dy[d], x += dx[d];
		st.push_back(d);
		for (int i = 0; i < g; i++) {
			for (int j = st.size()-1; j >=0; j--) {
				int tmp = (st[j] + 1) % 4;
				y += dy[tmp];
				x += dx[tmp];
				map[y][x] = true;
				st.push_back(tmp);
			}
		}
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (chk(i, j)) ans++;
		}
	}
	cout << ans << '\n';

	return 0;
}