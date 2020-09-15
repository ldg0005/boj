#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/special_functions/gamma.hpp>
#include <iostream>
using namespace std;
using namespace boost::multiprecision;

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cpp_dec_float_100 A, B, C;
	cin >> A >> B >> C;
	cpp_dec_float_100 x = 0;
	cpp_dec_float_100 left = -1, right = 100001, mid;
	cpp_dec_float_100 cost("0.0000000000000000000001");
	while(left <= right)
	{
		mid = (left + right) / 2;
		cpp_dec_float_100 tmp = (A * mid) + (B * (sin(mid)));
		if(tmp == C) break;
		else if(tmp < C) left = mid + cost;
		else right = mid - cost;
	}
	cout << fixed;
	cout.precision(6);
	cout << mid << endl;

	return 0;
}
