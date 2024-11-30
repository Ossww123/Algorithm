#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 3; i++) {
        int ih, im, is, oh, om, os, wh, wm, ws;
        cin >> ih >> im >> is >> oh >> om >> os;

        ws = os - is;
        if (ws < 0) {
            om--;
            ws += 60;
        }

        wm = om - im;
        if (wm < 0) {
            oh--;
            wm += 60;
        }

        wh = oh - ih;

        cout << wh << ' ' << wm << ' ' << ws << endl;
    }


    return 0;
}
