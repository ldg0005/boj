#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

#define f(x) floor(10000000000. * (x + 0.00000000005)) / 10000000000.

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << fixed;
	cout.precision(10);

	int A, B, C;
	cin >> A >> B >> C;
	double x = 0;
	while(1){
		if((A * x) + (B * (sin(x))) >= C) break;
		x++;
	}
	x--;
	double left = 0, right = 1;
	double mid;
	while(left<=right){
		mid = (left + right) / 2;
		double tmp = (A * (x + f(mid))) + (B * (sin(x + f(mid))));
		if(f(tmp) == C) break;
		else if(tmp > C) right = mid-0.00000000001;
		else left = mid+ 0.00000000001;
	}
	cout << x+f(mid) << '\n';


	return 0;
}
