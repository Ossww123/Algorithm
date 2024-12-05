#include <iostream>
#include <iomanip>  // setprecision을 사용하기 위한 헤더
#include <cmath>

using namespace std;

int main()
{
    float N;
    cin >> N;

    float answer = sqrt(N) * 4;

    // 소수점 이하 6자리까지 출력
    cout << fixed << setprecision(6) << answer;

    return 0;
}
