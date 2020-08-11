#include <iostream>
#include <cmath>
#include <iomanip>
#define ll long long
#define ld long double

ld calStd(ll first,ll last ,ll total, ld mean, ld count,int adjust) {
	ld sum_squared_diff_mean = std::pow(last - mean, 2);
	for (ll i = first; i != last; i = i + adjust)
	{
		sum_squared_diff_mean += std::pow(i - mean, 2);
	}
	ld ans = std::sqrt(sum_squared_diff_mean / (count - 1));
	return ans;
}

void adjust_print(ll x, ll y)
{
	ll total = y;
	ll count = 1;
	if (x == y)
	{
		std::cout << x;
		std::cout << "\nAverage = " << x << "\n";
		std::cout << "SD = 0.00";
		return;
	}
	int adjust = x > y ? -1 : 1;
	for (ll i = x; i != y; i = i + adjust)
	{
		std::cout << i << " ";
		total += i;
		count++;
	}

	ld mean = (ld)total / (ld)count;
	std::cout << y;
	std::cout << "\nAverage = " << mean << "\n";
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "SD = " <<calStd(x, y, total, mean, (ld)count, adjust);
}

int main()
{
	ll x, y;
	std::cin >> x >> y;
	adjust_print(x, y);
	return 0;
}