#include <iostream>
using namespace std;

int V, E;
int A[100001], B[100001], C[100001], p[10001];

void _qsort(int *a, int *b, int *c, int left, int right) {
	int l = left, r = right;
	register int pivot = c[(l + r) >> 1];
	while (l <= r) {
		while (c[l] < pivot) l++;
		while (c[r] > pivot) r--;
		if (l <= r) {
			swap(c[l], c[r]);
			swap(a[l], a[r]);
			swap(b[l], b[r]);
			l++, r--;
		}
	}
	if (left < r) _qsort(a, b, c, left, r);
	if (l < right) _qsort(a, b, c, l, right);
}
int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	p[x] = y;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) 
		cin >> A[i] >> B[i] >> C[i];
	_qsort(A, B, C, 0, E - 1);
	for (int i = 1; i <= V; i++) p[i] = i;
	
	int ans = 0;
	for (int i = 0; i < E; i++) {
		if (find(A[i]) == find(B[i])) continue;
		merge(A[i], B[i]);
		ans += C[i];
	}
	cout << ans << '\n';

	return 0;
}