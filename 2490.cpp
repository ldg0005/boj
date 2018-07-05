#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a[4] = { 0, };
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		for (int j = 0; j < 4; j++) {
			cin >> a[j];
			if (a[j] == 1) cnt++;
		}
		if (cnt == 0) cout << "D" << '\n';
		else if (cnt == 4) cout << "E" << '\n';
		else if (cnt == 1) cout << "C" << '\n';
		else if (cnt == 2) cout << "B" << '\n';
		else cout << "A" << '\n';
	}


	return 0;
}