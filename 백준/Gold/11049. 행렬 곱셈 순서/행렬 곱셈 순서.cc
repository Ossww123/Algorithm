#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
   long N;
   cin >> N;

   vector<pair<long, long>> matrix(N);
   for (long i = 0; i < N; i++) {
       long r, c;
       cin >> r >> c;
       matrix[i] = { r, c };
   }

   // dp[i][j] = i부터 j행렬까지 곱하는데 필요한 최소 연산
   vector<vector<long>> DP(N, vector<long>(N, 0));

   for (long l = 2; l <= N; l++) {
       for (long i = 0; i <= N - l; i++) {
           long j = i + l - 1;
           DP[i][j] = 2147483648;

           for (long k = i; k < j; k++) {
               // i~k까지 + (k+1)~j까지 + i * k * j 곱
               long cost = DP[i][k] + DP[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second;

               if (cost < DP[i][j]) {
                   DP[i][j] = cost;
               }
           }
       }
   }
   cout << DP[0][N-1] << endl;

   return 0;
}