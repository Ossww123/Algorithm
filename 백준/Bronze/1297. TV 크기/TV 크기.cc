#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int D, H, W;
	cin >> D >> H >> W;

	int real_H, real_W;
	
	real_H = static_cast<int>(D * sin(atan((double)H / (double)W)));
	real_W = static_cast<int>(D * cos(atan((double)H / (double)W)));

	cout << real_H << ' ' << real_W;

	return 0;
}