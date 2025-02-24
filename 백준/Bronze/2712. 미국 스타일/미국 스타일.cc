#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        double value;
        string unit;
        cin >> value >> unit;
        
        if (unit == "kg") {
            // kg를 lb로 변환 (1 kg = 2.2046 lb)
            cout << fixed << setprecision(4) << value * 2.2046 << " lb\n";
        }
        else if (unit == "lb") {
            // lb를 kg로 변환 (1 lb = 0.4536 kg)
            cout << fixed << setprecision(4) << value * 0.4536 << " kg\n";
        }
        else if (unit == "l") {
            // l를 g로 변환 (1 l = 0.2642 g)
            cout << fixed << setprecision(4) << value * 0.2642 << " g\n";
        }
        else if (unit == "g") {
            // g를 l로 변환 (1 g = 3.7854 l)
            cout << fixed << setprecision(4) << value * 3.7854 << " l\n";
        }
    }
    
    return 0;
}