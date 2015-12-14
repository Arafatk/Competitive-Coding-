#include <bits/stdc++.h>
using namespace std;
#define forall(i,a,b)               for(long long i=a;i<b;i++)
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define ll long long
int dif[120];
// the function to write m in base n which return size of num too
std::vector<ll> binary;

void difbase(ll m,ll n){ 
  if(binary.size())binary.erase(binary.begin(),binary.end());
  vector<ll> dif;ll i=0;while(m){dif.pb((m%n));m/=n;i++;}
                          ll len=dif.size();forall(i,0,len){binary.pb(dif[len-i-1]);}}
                          
int main()
{
    int n,m;cin >> n >> m;
    int size=difbase(m,n);size--;
     forall(i,0,binary.size())cout << binary[i] <<; 
}
