#include <string>
#include <vector>
#include <map>

using namespace std;

int MAXTIME = 1439;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<int, int> carRecords;
    map<int, int> carTotalTime;
    
    for (string record : records)
    {
        string s_hour       = record.substr(0, 2);
        string s_min        = record.substr(3, 2);
        string s_carNum     = record.substr(6, 4);
        string s_io         = record.substr(11);
        
        int hour = stoi(s_hour);
        int min = stoi(s_min);
        int carNum = stoi(s_carNum);
        bool isIn = (s_io == "IN");
        
        int totalMin = hour * 60 + min;
        
        if (isIn)
        {
            carRecords[carNum] = totalMin;
        }
        else
        {
            carTotalTime[carNum] += (totalMin - carRecords[carNum]);
            carRecords.erase(carNum);
        }
    }
    
    for (auto carRecord : carRecords)
    {
        carTotalTime[carRecord.first] += (MAXTIME - carRecord.second);
    }

    
    vector<int> answer;
    for (auto a : carTotalTime)
    {
        int time = a.second;
        int fee = 0;
        if (time <= fees[0])
        {
            fee = fees[1];
        }
        else
        {
            int temp = time - fees[0];
            fee = fees[1];
            while (temp > 0)
            {
                temp -= fees[2];
                fee += fees[3];
            }
        }
        answer.push_back(fee);
    }
    return answer;
}