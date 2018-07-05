#include <iostream>
using namespace std;

int arr[26];
char str[101];

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	for (int i = 0; str[i]; i++)
		arr[str[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";

	return 0;
}