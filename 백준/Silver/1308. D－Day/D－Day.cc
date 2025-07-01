#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isLeapYear(int iYear)
{
    bool ret = false;

    if (0 == iYear % 4)
    {
        ret = true;
    }

    if (0 == iYear % 100)
    {
        ret = false;
    }

    if (0 == iYear % 400)
    {
        ret = true;
    }

    return ret;
}

int main()
{
    int sYear, sMonth, sDay, eYear, eMonth, eDay;
    cin >> sYear >> sMonth >> sDay >> eYear >> eMonth >> eDay;

    if (1000 < eYear - sYear
        || ((1000 == eYear - sYear) && (sMonth < eMonth))
        || ((1000 == eYear - sYear) && (sMonth == eMonth) && (sDay <= eDay))
        )
    {
        cout << "gg";
    }
    else
    {
        int totalDays = 0;

        for (int year = sYear; year < eYear; year++)
        {
            if (isLeapYear(year))
            {
                totalDays += 366;
            }
            else
            {
                totalDays += 365;
            }
        }

        vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        for (int month = 1; month < eMonth; month++)
        {
            if (month == 2 && isLeapYear(eYear))
            {
                totalDays += 29;
            }
            else
            {
                totalDays += daysInMonth[month - 1];
            }
        }

        totalDays += eDay;

        for (int month = 1; month < sMonth; month++)
        {
            if (month == 2 && isLeapYear(sYear))
            {
                totalDays -= 29;
            }
            else
            {
                totalDays -= daysInMonth[month - 1];
            }
        }

        totalDays -= sDay;

        cout << "D-" << totalDays;
    }



    return 0;
}