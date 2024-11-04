#include <iostream>
using namespace std;
int main()
{
	int left, mid, right;
	cin >> left >> mid >> right;
	
	int avg = (left + mid + right) / 3;

	int total = 0;

	int nl, nm, nr;
	nl = left - avg;
	nm = mid - avg;
	nr = right - avg;

	if (nm < 0) {
		total += -nl * 2 + (-nm);
	}
	else if (nm == 0) {
		total += nr * 2;
	}
	else {
		total += nr * 2 + nm;
	}

	cout << total;

	return 0;
}