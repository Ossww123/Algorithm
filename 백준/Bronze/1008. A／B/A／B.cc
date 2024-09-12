#include <iostream>
#include <iomanip> // for std::setprecision
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    // 출력 시 소수점 이하 9자리까지 출력하도록 설정
    cout << fixed << setprecision(9) << a / b << endl;
    return 0;
}
