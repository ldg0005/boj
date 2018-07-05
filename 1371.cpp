#include <iostream>
using namespace std;

int table[26];

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	char tmp;
	int maxnum = 0;
	while (cin >> tmp) {
		if (tmp >= 'a' && tmp <= 'z') {
			table[tmp - 'a']++;
			maxnum = maxnum > table[tmp - 'a'] ? maxnum : table[tmp - 'a'];
		}
	}
	for (int i = 0; i < 26; i++)
		if (maxnum == table[i]) cout << (char)(i + 'a');

	return 0;
}