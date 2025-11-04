#include <string>
#include <vector>

typedef long long ll;

using namespace std;

bool Simul(ll m, ll n, vector<int>& times){
    ll sum = 0;
    
    for(int t:times){
        sum += (m / t);
    }
    
    return n <= sum;
}

long long solution(int n, vector<int> times) {
    ll l = 1, r = 0;
    for (int t : times) if ((ll)t > r) r = t;
    r *= (ll)n;
    
    ll answer = -1;
    
    while(l <= r){
        ll mid = (l + r) / 2;
        if (Simul(mid, n, times)){
            answer = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1; 
        }
    }
    
    return answer;
}