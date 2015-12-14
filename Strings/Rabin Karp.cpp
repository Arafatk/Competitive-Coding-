#include <bits/stdc++.h>
using namespace std;

#define linf                        (long long)1e18
#define inf                         (int)1e9
#define forall(i,a,b)               for(int i=a;i<b;i++)

// Useful container manipulation / traversal macros
#define forbac(i,a,b)               for(int i=a;i>=b;i--)
#define foreach(v, c)               for(typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ((b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof (a))
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair

// comparision Guys 
#define abs(a)                       ( (a) > (0) ? (a) : (-a))
#define DREP_sort(a)                 sort(all(a)); a.erase(unique(all(a)),a.end()) //deletes repeat sorted
#define DREP(a)                      a.erase(unique(all(a)),a.end()) //deletes repeat

// The bit standard guys
#define bit(x,i)                    (x&(1<<i))  //select the bit of position i of x
#define lowbit(x)                   ((x)&((x)^((x)-1))) //get the lowest bit of x
#define highbit(x)                  (1 << (int) log2(x) ) // the highest bit becareful
#define bitcount(x)                 __builtin_popcount(x)  // counts 1 eg- 1101 has value 3
#define zerotrail(x)                __builtin_ctz(x)  // returns number of trailing 0-bits of x 
// with bitcount be careful with data types

// The vectors and pairs
typedef vector<int>   vi;
typedef vector<vi>   vvi;
typedef pair<int,int> pi;
typedef map<int,int>hash;
#define ft                 first
#define sd                 second

// the data types
#define ll long long
#define st string
st text,pattern; 
ll M=1000007,ht,hp,n,m; // NEver pick main mod with a divisor

/*
    This is a good way to generate up the hash values and check 
    if a pattern is found   inside a string and also how many 
    times its found in a string this could also     be used to 
    generate tha standard hashing techniques necessary for 
    also their is such a thing as collision of hashes in which 
    case the best techniques is to use a different value of b=3
    with this so that we get what we get to double check our 
    solutions and if they still match maybe thats when you need to check 
    
    Problems
    find the most frequent substring of a fixed length in a given text. 
    Since the length is already fixed 
    we do not need any BS. We just use a hash table and keep 
    track of the frequencies.
    
    

*/

ll mod(ll a,ll b){ll h=(a%b+b)%b;return h;} // Perfect mod function

ll e(ll b,ll p)  {ll m=1;forall(j,0,p-1)m=((m%M)*(b%M))%M;return m; } 
// This is for e=b^(m-1) where m is the length of pattern

void hashval(ll b)
{
    hp=ht=0;
    if(n<m)return;
    forall(i,0,m){hp=mod(hp*b+pattern[i],M);ht=mod(ht*b+text[i],M);};
    if(ht==hp)cout << "found at 1\n";
    ll E=e(b,m);
    forall(i,m,n)// this gives the hash value of the string end at i index 
    {
        ht=mod((ht-mod(text[i-m]*E,M)),M);
        ht=mod(ht*b,M);
        ht=mod(ht+text[i],M);
        if(ht==hp)cout <<"found at " << (i-m+1) <<"\n";
        
    }
}


int main()
{
    cin >> text >> pattern;n=text.length();m=pattern.length();
    hashval(2);// we use the power of two idea
    
    
}
/*
Rabin karp is an easy way to check if a pattern is inside another
now this can be used to do the same thing as knuth morris pratt
except it is much easier to implement and code

*/