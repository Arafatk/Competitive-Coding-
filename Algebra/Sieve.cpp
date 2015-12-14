#include <bits/stdc++.h>
using namespace std;
int    dist[5000001];
int     cnt[5000001];
int isPrime[110000];
void sieveOptimized(int N) {
    for (int i = 2; i <= N; i++)
        isPrime[i] = 1;
    for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) 
                isPrime[j] = 0;
        }
    }
}
int main()
{


    sieveOptimized(1000);
  for(int j=0;j<1000;j++)if(isPrime[j])cout <<j <<"\n";

}
