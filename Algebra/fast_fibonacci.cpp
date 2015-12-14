#include <bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
using namespace std;
typedef long long ll;
map<long long, long long> F;
ll m=1000000007;
long long f(long long n) {
	if (F.count(n))
		return F[n];
	long long k = n / 2;
	if (n % 2 == 0)
		return F[n] = (f(k) * f(k)     + f(k - 1) * f(k - 1)) % m;
    else  
		return F[n] = (f(k) * f(k + 1) + f(k)     * f(k - 1)) % m;
}
int main()
{
    F[0] = F[1] = 1;
    ll n;cin >> n; // This answers the term n
    cout << f(n-1);
}


