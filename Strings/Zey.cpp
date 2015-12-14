#include <bits/stdc++.h>
using namespace std;

#define INF                         (int)1e9
#define forall(i,a,b)               for(int i=a;i<b;i++)

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define forbac(i,a,b)               for(int i=a;i>=b;i--)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// comparision Guys 
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define abs(a)                       ( (a) > (0) ? (a) : (-a))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat

// The bit standard guys
#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n)        asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define higbit(x)                   (1 << ( int) log2(x) )
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3
// with bitcount be careful with data types

// The vectors and pairs
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define ft                 first
#define sd                 second

// the data types
#define ll long long
#define st string

// Fast io 
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;

string s;int z[1000];
/*
  This is a Z algorithm with complete explaination found here
  http://codeforces.com/blog/entry/3107 And it can be use
   both  for prefix suffix matching and Pattern occurence 
  To match occurences of P in S just pass P+S as the string 
  and check how many have z[i] >=length of p
*/

void zey()
{
    int L = 0, R = 0,n=s.length();
    
    for (int i = 1; i < n; i++) {
    if (i > R) {L = R = i;while (R < n && s[R-L] == s[R]) R++;z[i] = R-L; R--;} 
    
    else {int k = i-L;
          if (z[k] < R-i+1) z[i] = z[k];
          else {L = i;while (R < n && s[R-L] == s[R]) R++;z[i] = R-L; R--;}}}return;}
          

int main()
{
   cin >> s;   zey();
   int len=s.length();forall(i,1,len)cout << z[i] <<" ";
}
/*
ABACABA
*/            
                
