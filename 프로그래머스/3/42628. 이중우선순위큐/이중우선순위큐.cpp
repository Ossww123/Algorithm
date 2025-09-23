#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> pq;
    
    for (string op : operations) {
        istringstream iss(op);
        string command;
        iss >> command;
        
        if (command == "I") {
            int num;
            iss >> num;
            pq.insert(num);
        }
        
        else if (command == "D" && !pq.empty()) {
            int flag;
            iss >> flag;
            if (flag == 1) {
                pq.erase(prev(pq.end()));
            }
            else if (flag == -1) {
                pq.erase(pq.begin());
            }
        }
    }
    
    if (pq.empty()) {
        return { 0, 0};
    }
    
    return {*pq.rbegin(), *pq.begin()};
}