#include <iostream>
using namespace std;

char str[101];

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin.getline(str, sizeof(str));
	for (int i = 0; str[i]; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			int n = str[i] - 'a' + 13;
			if (n >= 26) n %= 26;
			str[i] = n + 'a';
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			int n = str[i] - 'A' + 13;
			if (n >= 26) n %= 26;
			str[i] = n + 'A';
		}
	}
	cout << str << '\n';

	return 0;
}