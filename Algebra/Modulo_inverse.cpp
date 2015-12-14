#include <bits/stdc++.h>
using namespace std;
 
#define forall(i,a,b)               for(long long i=a;i<b;i++)
#define forbac(i,a,b)               for(long long i=a;i>=b;i--)
#define foreach(v, c)               for(typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ((b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof (a))
#define sz(a)                       ((ll )(a.size()))
#define mp                          make_pair
#define ll long long

/*
x= inverse mod of a 
If you want to get 
a*x=1(mod m)
then for the inverse to exists gcd (a,m)=1
https://www.youtube.com/watch?v=mgvA3z-vOzc&feature=iv&src_vid=ru7mWZJlRQg&annotation_id=annotation_768190147
use the euclids theorem to get gcd as 1 and then 
Express all the equations as the form of 1 to get the 
original equation back again 
Move backwards in your solutions to achieve  the numbers at start 

*/