#include <bits/stdc++.h>
using namespace std;

#define INF                         (int)1e9
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define bitcount                    __builtin_popcount  // counts 1 eg- 1101 has value 3
// with bitcount be careful with data types

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
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
#define higbit(x)                   (1 << ( int) log2(x) )

// The vectors and pairs
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
#define ft                 first
#define sd                 second

// the data types
#define ll long long
#define st string



int x[60][26], next = 1;      //initially all numbers in x are -1

int checker(string s)
{
    
    int i = 0, v = 0,matching=0;   // this variable matching tests for equal thing in tree
	while(i < s.size()){
		if(x[v][s[i]] == 0)
			v = x[v][s[i++]] = next ++;
		else
			v = x[v][s[i++]],matching++,next++;
	}
    if(matching==s.size())return -123;
    else return matching;
    
}
int main()
{
    
        // Building part 
        string a="reerror",b="terrific",c="aerrifyqqg",d="derribe",e="weedex";
        checker(a);checker(b);checker(c);checker(d);checker(e);
    
    /* now i ask the user for a number of string that are added to every string that is asked for
       is automatically added to the string and if the string matches any other string or is the
       prefix of any other string in the trie 
       the output is  -123  
       if  it shares a prefix with other strings then we output the length of the
       logest prefix it shares with the other string */
    string read;
    forall(i,0,10)
    {
        cin >> read;int num=checker(read);cout << num << "\n";
    }}
/*
terror
ter
teddy
tede
*/
    
    
    
    
    
