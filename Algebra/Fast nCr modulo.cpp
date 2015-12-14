#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<list>
using namespace std;

// Input macros
#define s(n)                        scanf("%ld",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ss(n)                       scanf("%s",n)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

#define getI(a)                      scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b)                   scanf("%d%d", &a, &b)
#define getIII(a,b,c)                scanf("%d%d%d", &a, &b, &c)
#define w(n) int (n);                scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define w2(n,m) int (n),(m);         scanf("%d %d",&(n),&(m))
#define w3(n,m,k) int (n),(m),(k);   scanf("%d %d %d",&(n),&(m),&(k))
#define ll long long
typedef int elem_t;
long long C[100][100];
long long C(long long n, long long r, long long MOD)
{
   

    for (long long i=0; i<=n; i++)
    {
     for (long long k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)   C[i][k] = 1;
            else                C[i][k] = (C[i-1][k-1] + C[i-1][k])%MOD;
                
    }
    return C[n][r];
}
int main()
{
    int n,r,m;
    m=10000007;
    while (scanf("%d%d",&n,&r))
    {
        if(n>=r) printf("%lld\n",C(n, r, m));
        else     printf("-1");
    }
}
