#include <iostream>
using namespace std;

char str[101];

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin.getline(str,sizeof(str))) {
		int ans[4] = { 0, };
		for (int i = 0; str[i]; i++) {
			if (str[i] >= 'a' && str[i] <= 'z') ans[0]++;
			else if (str[i] >= 'A' && str[i] <= 'Z') ans[1]++;
			else if (str[i] >= '0' && str[i] <= '9') ans[2]++;
			else if (str[i] == ' ') ans[3]++;
		}
		cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << '\n';
	}


	return 0;
}