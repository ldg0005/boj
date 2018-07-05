#include <iostream>
using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int x = 64,ans=0;
	for (int i = 0; i <= 6; i++) {
		if (N >= x) {
			N -= x;
			ans++;
			x >>= 1;
		}
		else x >>= 1;
	}
	cout << ans << '\n';

	return 0;
}