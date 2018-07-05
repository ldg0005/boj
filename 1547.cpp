#include <iostream>
using namespace std;

int N;
bool map[4];

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int x, y;
	map[1] = true;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		swap(map[x], map[y]);
	}
	for (int i = 1; i < 4; i++) if (map[i]) cout << i << '\n';

	return 0;
}